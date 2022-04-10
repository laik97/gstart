#!/bin/bash

sudo apt-get update && sudo apt-get install -y \
    build-essential \
    wget \
    git \
    gcc \
    clang \
    g++ \
    libegl1-mesa \
    libgl1-mesa-dev \
    libglu1-mesa \
    libglu1-mesa-dev \
    libsfml-dev \
    libgtest-dev \
    binutils-dev \
    libtool \
    lua5.2 \
    liblua5.2-dev \
    liblua5.2-0

# apt install -y \
#     libegl1-mesa \
#     libgl1-mesa-dev \
#     libglu1-mesa \
#     libglu1-mesa-dev \
#     libsfml-dev \
#     libgtest-dev \
#     binutils-dev \
#     libtool \
#     lua5.2 \
#     liblua5.2-dev \
#     liblua5.2-0
