# Data Structure and Algorithms Based on LeetCode
[![Build Status][travis-badge]][travis-link]
[![codecov][codecov-badge]][codecov-link]
[![MIT License][license-badge]](LICENSE.md)

Solutions and practices for data structure and algorithms (DSA), refering to the high frequency questions in [LeetCode](https://leetcode.com/problemset/all/).  
All the solutions are located in the `\src` dir. It only supports C++/C++11 now.   
The solution for every question has run pass the tests online and explains the detailed methods with its complexity in the `\doc` and every source code in `\src`.
## Built With

This project is built with following tools: 
 * C++ version: `C++11`
 * Build system: [`CMake`](https://cmake.org/)
 * C++ compiler: `g++`
 * Libraries: `STL` only
 * Code coverage: [`lcov`](http://ltp.sourceforge.net/coverage/lcov.php) (note: it should show the code coverage is below 100%)
 * [`CodeCov`](https://codecov.io/) (code coverage is measured by CodeCov).
 * Source & Tests: [`\src`](\src)

## Prerequisites

To build the project you need to install `CMake`. [Here](https://cmake.org/install/) are the instructions. To create code coverage report you need to install `lcov`. [`Download lcov`](http://ltp.sourceforge.net/coverage/lcov.php) from here you can download latest `lcov` and here are [`instructions`](http://ltp.sourceforge.net/coverage/lcov/readme.php). This reports will be later uploaded to CodeCov servers.


### The DSA contains the following aspects:
1. Basic operations for basic data structures.
    * array, single linked list
    * stack, queue
    * priority queue
    * skip list
    * hash 
2. Operations for tree.
    * Binary search tree (BST).
    * Heap
    * Advanced BST
        * RB tree
        * AVL tree
        * Splay tree
        * B-/B+/B* tree
3. Operations for Graph.
4. Dynamic programing.
5. Other algorithms.


## License

This project is licensed under the MIT License - see the [LICENSE](https://github.com/RokKos/classes-c-/blob/master/LICENSE) file for details.

[![Build Status](https://travis-ci.org/yjjnls/LeetCode.svg?branch=master)](https://travis-ci.org/yjjnls/LeetCode.svg?branch=master)

[travis-badge]:    
https://travis-ci.org/yjjnls/LeetCode.svg?branch=master
[travis-link]:     
https://travis-ci.org/yjjnls/LeetCode
[license-badge]:   https://img.shields.io/badge/license-MIT-007EC7.svg