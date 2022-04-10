#!/bin/bash

PROJECT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

function rebuild() {
    rm -rf $PROJECT_DIR/build
    mkdir -p $PROJECT_DIR/build
    cd $PROJECT_DIR/build
    cmake .. "$@"
    make -j12
    cd $PROJECT_DIR
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
