#!/bin/bash

PS1="\e[1;36m(gtest) \e[0m \e[1;34m\u@\h\e[0m:\e[1;32m\w\e[0m$ "

PROJECT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)
TEST_RESULTS_PATH=$PROJECT_DIR/Testing

export LD_LIBRARY_PATH="${PROJECT_DIR}/libs/sfml/lib:${LD_LIBRARY_PATH}"
# export LD_LIBRARY_PATH="${PROJECT_DIR}/libs/gtest/lib:${LD_LIBRARY_PATH}"
export LD_LIBRARY_PATH="${PROJECT_DIR}/libs/gtest/build/lib:${LD_LIBRARY_PATH}"
export LD_LIBRARY_PATH="${PROJECT_DIR}/libs/libtorch/lib:${LD_LIBRARY_PATH}"

function info() {
    echo ""
    echo "************ gstart setup.bash functions ************"s
    echo ""

    cd ${PROJECT_DIR}
    cat setup.bash | grep -E "(^function)"

    echo ""
    echo "************ gstart setup.bash functions ************"
    echo ""
}

function setupEnv() {
    "${PROJECT_DIR}"/scripts/essentials.sh download_externals
}

function cleanRepo() {
    cd "${PROJECT_DIR}"
    rm -rf libs
    rm -rf build
    rm -rf Testing
}

function build() {
    mkdir -p ${PROJECT_DIR}/build
    cd ${PROJECT_DIR}/build
    cmake .. "$@"
    make -j12
    cd ${PROJECT_DIR}
}

function rebuild() {
    rm -rf ${PROJECT_DIR}/build
    build "$@"
}

function rebuildDebug() {
    rebuild -DCMAKE_BUILD_TYPE=Debug
}

function run() {
    echo ""
    echo "************  Running gstart ************"
    echo ""

    ${PROJECT_DIR}/build/bin/gstartMain "$@"

    echo ""
    echo "************  Running gstart ************"
    echo ""
}

function rerun() {
    build
    run "$@"
}

function level_creator() {
    echo ""
    echo "************  Running LevelCreator ************"
    echo ""

    ${PROJECT_DIR}/build/bin/level_creator "$@"

    echo ""
    echo "************************"
    echo ""

}

function run_unit_tests() {
    echo ""
    rm -rf $TEST_RESULTS_PATH
    mkdir -p $TEST_RESULTS_PATH
    cd ${PROJECT_DIR}/build
    ctest --verbose -R Test
    cd ${PROJECT_DIR}
    echo ""
}

function run_cppcheck() {
    cppcheck --verbose --std=c++11 --enable=warning,style,performance,portability,unusedFunction --language=c++ "${PROJECT_DIR}/src"
}

function run_valgrind_with_suppression() {

    echo "gstartMain flags : $@"
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=/home/wiktor/private/gstart/valgrind_nvidia_lib_suppression.supp ${PROJECT_DIR}/build/bin/gstartMain "$@"
}

function create_valgrind_suppressions() {
    echo "Running valgrind.."
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --gen-suppressions=all --log-file=./val.txt ${PROJECT_DIR}/build/bin/gstartMain "$@"
    echo "Parsing suppressed blocks"
    python3 ${PROJECT_DIR}/valgrind_suppresion_creator.py --log_path ${PROJECT_DIR}/val.txt
    rm -f ${PROJECT_DIR}/val.txt
}

$@
