#!/bin/bash
__dir__=$( cd $(dirname ${BASH_SOURCE[0]}); pwd )

wget https://github.com/google/googletest/archive/release-1.8.0.tar.gz
tar xf release-1.8.0.tar.gz
cd googletest-release-1.8.0
cmake -DBUILD_SHARED_LIBS=ON .

make
make -p __dir__/include
make -p __dir__/lib
cp -af googletest/include __dir__/include
cp -af googlemock/gtest/libgtest_main.so googlemock/gtest/libgtest.so __dir__/lib

