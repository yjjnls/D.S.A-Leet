#!/bin/bash
__dir__=$( cd $(dirname ${BASH_SOURCE[0]}); pwd )

mkdir -p build && cd build
rm -rf *

mkdir -p $__dir__/build/include

mkdir -p $__dir__/build/lib



wget https://github.com/google/googletest/archive/release-1.8.0.tar.gz
tar xf release-1.8.0.tar.gz
cd googletest-release-1.8.0
cmake -DBUILD_SHARED_LIBS=ON .

make
cp -af googletest/include/gtest $__dir__/build/include
cp -af googlemock/gtest/libgtest_main.so googlemock/gtest/libgtest.so $__dir__/build/lib