# Data Structure and Algorithms Based on LeetCode

[![Build Status][travis-badge]][travis-link]
[![codecov][codecov-badge]][codecov-link]
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/3cdacea7ff0d4c738f9689b82f40f10c)](https://www.codacy.com/app/yjjnls/LeetCode?utm_source=github.com&utm_medium=referral&utm_content=yjjnls/LeetCode&utm_campaign=badger)
[![MIT License][license-badge]](LICENSE.md)  
[![stability-experimental](https://img.shields.io/badge/stability-experimental-orange.svg)](https://github.com/emersion/stability-badges#experimental)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](http://makeapullrequest.com)  
![Examples](https://img.shields.io/badge/%F0%9F%92%A1-examples-8C8E93.svg)
[![Badges](http://img.shields.io/:badges-6/6-ff6799.svg)](https://github.com/badges/badgerbadgerbadger)
<!-- [![Latest Stable Version](https://poser.pugx.org/matthiasnoback/badges/v/stable.png)](https://packagist.org/packages/matthiasnoback/badges) -->
<!-- [![Latest Unstable Version](https://poser.pugx.org/matthiasnoback/badges/v/unstable.png)](https://packagist.org/packages/matthiasnoback/badges) -->

<!-- [![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.svg?v=103)](https://github.com/ellerbrock/open-source-badges/)   -->


Solutions and practices for data structure and algorithms (DSA), refering to the high frequency questions in [LeetCode](https://leetcode.com/problemset/all/).  

All the solutions are located in the `\src` dir. It only supports C++/C++11 now.    

The solution for every question has run pass the tests online and explains the detailed methods with its complexity in the `\doc` and every source code in `\src`.

## Built With

This project is built with following tools: 

-   C++ version: `C++11`
-   Build system: [`CMake`](https://cmake.org/)
-   C++ compiler: `g++`
-   Libraries: `STL` only
-   Code coverage: [`lcov`](http://ltp.sourceforge.net/coverage/lcov.php) (note: it should show the code coverage is below 100%)
-   [`CodeCov`](https://codecov.io/) (code coverage is measured by CodeCov).
-   Source & Tests: [`\src`](https://github.com/yjjnls/LeetCode/tree/master/src)

## Prerequisites

To build the project you need to install `CMake`. [Here](https://cmake.org/install/) are the instructions. To create code coverage report you need to install `lcov`. [`Download lcov`](http://ltp.sourceforge.net/coverage/lcov.php) from here you can download latest `lcov` and here are [`instructions`](http://ltp.sourceforge.net/coverage/lcov/readme.php). This reports will be later uploaded to CodeCov servers.

## Knowledge summary

The basic knowledge of various data structures and algorithms, along with **`their applications in LeetCode problems`** are summarized in [`\doc`](https://github.com/yjjnls/LeetCode/tree/master/doc).Detailed contents are shown below:  

1.  Basic operations for basic data structures.
    -   array, single linked list
    -   stack, queue
    -   priority queue
    -   skip list
    -   hash 
2.  Operations for tree.
    -   Binary search tree (BST).
    -   Heap
    -   Advanced BST
        -   RB tree
        -   AVL tree
        -   Splay tree
        -   B-/B+/B\* tree
3.  Operations for Graph.
4.  Dynamic programing.
5.  Other algorithms.

## Authors

-   [**yjjnls**](https://github.com/yjjnls)

## License

This project is licensed under the MIT License - see the [LICENSE](https://github.com/RokKos/classes-c-/blob/master/LICENSE) file for details.

[travis-badge]: https://travis-ci.org/yjjnls/LeetCode.svg?branch=master
[travis-link]: https://travis-ci.org/yjjnls/LeetCode

[codecov-badge]:   https://codecov.io/gh/yjjnls/LeetCode/branch/master/graph/badge.svg
[codecov-link]:    https://codecov.io/gh/yjjnls/LeetCode

[license-badge]: https://img.shields.io/badge/license-MIT-007EC7.svg


