#!/bin/bash

PS1="\e[1;36m(gtest) \e[0m \e[1;34m\u@\h\e[0m:\e[1;32m\w\e[0m$ "

PROJECT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)
TEST_RESULTS_PATH=$PROJECT_DIR/Testing
export LD_LIBRARY_PATH="${PROJECT_DIR}/libs/sfml/lib:${LD_LIBRARY_PATH}"
export LD_LIBRARY_PATH="${PROJECT_DIR}/libs/gtest/lib:${LD_LIBRARY_PATH}"
export LD_LIBRARY_PATH="${PROJECT_DIR}/libs/gtest/build/lib:${LD_LIBRARY_PATH}"

function build() {
    cd $PROJECT_DIR/build
    cmake .. "$@"
    make -j12
    cd $PROJECT_DIR
}

function rebuild() {
    rm -rf $PROJECT_DIR/build
    mkdir -p $PROJECT_DIR/build
    build "$@"
}

function run_unit_tests() {
    echo ""
    rm -rf $TEST_RESULTS_PATH
    mkdir -p $TEST_RESULTS_PATH
    cd $PROJECT_DIR/build
    ctest --verbose -R Test
    cd $PROJECT_DIR
    echo ""
}

function run() {
    echo ""
    echo "************  Running gstart ************"
    echo ""

    cd $PROJECT_DIR/build/src
    ./gstartMain
    cd $PROJECT_DIR

    echo ""
    echo "************  Running gstart ************"
    echo ""
}

function rebuildDebug() {
    rebuild -DCMAKE_BUILD_TYPE=Debug
}

function rerun() {
    rebuild
    run
}

function run_cppcheck() {
    cppcheck --verbose "${PROJECT_DIR}/src"
}

function info() {
    echo ""
    echo "************ gstart setup.bash functions ************"
    echo ""

    cd $PROJECT_DIR
    cat setup.bash | grep -E "(^function)"

    echo ""
    echo "************ gstart setup.bash functions ************"
    echo ""
}

$@
