/*

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.


*/
#include <common.hpp>
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
    }
};

/*
solution 1 brute force
和01matrix一样，遍历矩阵，遇到一个1就逐步向右边和底边遍历，看是否都是1
如果都是1，那么square的边长+1，否则跳出这个循环

time:O(mn*mn)
space:O(1) 矩阵的存储空间不算

solution 2

*/