#!/bin/bash

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

function install_dependencies() {
    sudo apt-get update && sudo apt-get install -y \
        build-essential \
        wget \
        git \
        gcc \
        clang \
        g++ \
        libegl1-mesa \
        libxrandr-dev \
        libvorbis-dev \
        libudev-dev \
        libopenal-dev \
        libgl1-mesa-dev \
        libfreetype6-dev \
        libflac-dev \
        libglu1-mesa \
        libglu1-mesa-dev \
        libx11-dev \
        libgtest-dev \
        binutils-dev \
        libtool \
        lua5.2 \
        liblua5.2-dev \
        liblua5.2-0 \
        doxygen \
        cppcheck
}

function clean_dependencies() {
    sudo apt-get purge -y libcsfml-audio2.5 \
        libcsfml-dev \
        libcsfml-doc \
        libcsfml-graphics2.5 \
        libcsfml-network2.5 \
        libcsfml-system2.5 \
        libcsfml-window2.5 \
        libsfml-audio2.5 \
        libsfml-dev \
        libsfml-doc \
        libsfml-graphics2.5 \
        libsfml-network2.5 \
        libsfml-system2.5 \
        libsfml-window2.5
}

function download_sfml() {
    cd "${SCRIPT_DIR}/../libs"
    if [ ! -d "./SFML-2.5.1" ]; then
        mkdir -p sfml
        wget https://www.sfml-dev.org/files/SFML-2.5.1-linux-gcc-64-bit.tar.gz
        tar -zxvf SFML-2.5.1-linux-gcc-64-bit.tar.gz --strip 1 -C ./sfml 1>/dev/null
        rm -f *".tar.gz"
    else
        echo "SFML already installed"
    fi
    cd "${SCRIPT_DIR}/../"
}

function download_gtest() {
    cd "${SCRIPT_DIR}/../libs"
    if [ ! -d "./gtest" ]; then
        mkdir -p gtest
        wget https://github.com/google/googletest/archive/release-1.11.0.tar.gz
        tar -zxvf release-1.11.0.tar.gz --strip 1 -C ./gtest 1>/dev/null
        rm -f *".tar.gz"
    else
        echo "gtest already installed"
    fi
    cd "${SCRIPT_DIR}/../"
}

function download_externals() {
    download_sfml
    download_gtest
}

$@
