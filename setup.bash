#!/bin/bash

PROJECT_DIR="$(pwd)"

function rebuild()
{
    rm -rf $PROJECT_DIR/build
    mkdir -p $PROJECT_DIR/build
    cd $PROJECT_DIR/build
    cmake .. "$@"
    make -j12
    cd $PROJECT_DIR
}

function run()
{
    echo "########################"
    echo "   Running gstart ..."
    echo "########################"

    cd $PROJECT_DIR/build/src
    ./gstartMain
    cd $PROJECT_DIR
}

function rebuildDebug()
{
    rebuild -DCMAKE_BUILD_TYPE=Debug
}

function rerun()
{
    rebuild
    run
}

$@