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
        doxygen
}

function download_sfml() {
    cd "${SCRIPT_DIR}/../libs"
    if [ ! -d "./SFML-2.5.1" ]; then
        wget https://www.sfml-dev.org/files/SFML-2.5.1-linux-gcc-64-bit.tar.gz
        tar -zxvf SFML-2.5.1-linux-gcc-64-bit.tar.gz 1>/dev/null
        rm -f *".tar.gz"
    else
        echo "SFML already installed"
    fi
}

$@
