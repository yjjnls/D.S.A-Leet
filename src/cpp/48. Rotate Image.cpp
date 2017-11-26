/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:
You have to rotate the image in-place, which means you have to modify the input
2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/
#include <common.hpp>
class Solution1
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int row = 0;
        int col = n - 1;
        while (row < col)
        {
            for (int i = 0; i < (col - row); ++i)
            {
                std::swap(matrix[row][row + i], matrix[row + i][col]);
                std::swap(matrix[row][row + i], matrix[col][col - i]);
                std::swap(matrix[row][row + i], matrix[col - i][row]);
            }
            ++row;
            --col;
        }
    }
};

//time:O(N^2)
//space:O(1)

//common method to rotate image
/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
class Solution2
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = i + 1; j < matrix[i].size(); ++j)
                std::swap(matrix[i][j], matrix[j][i]);
        }
    }
};

/*
* anticlockwise rotate
* first reverse left to right, then swap the symmetry
* 1 2 3     3 2 1     3 6 9
* 4 5 6  => 6 5 4  => 2 5 8
* 7 8 9     9 8 7     1 4 7
*/
void anti_rotate(vector<vector<int>> &matrix)
{
    for (auto vi : matrix)
        reverse(vi.begin(), vi.end());
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            std::swap(matrix[i][j], matrix[j][i]);
    }
}