/*
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
Example 1: 
Input:

0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0
Example 2: 
Input:

0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
Note:
The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.
*/
#include <common.hpp>
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0)
            return matrix;

        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> res(row, vector<int>(col, INT_MAX));
        // init container
        std::queue<std::pair<int, int>> q;

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty())
        {
            // pop element form container
            std::pair<int, int> cur = q.front();
            q.pop();
            int cur_row = cur.first;
            int cur_col = cur.second;

            for (int i = 0; i < 4; ++i)
            {
                int neigh_row = cur.first + direction[i][0];
                int neigh_col = cur.second + direction[i][1];

                if (neigh_row >= 0 && neigh_col >= 0 &&
                    neigh_row < row && neigh_col < col)
                {
                    if (res[neigh_row][neigh_col] > res[cur_row][cur_col] + 1)
                    {
                        res[neigh_row][neigh_col] = res[cur_row][cur_col] + 1;
                        q.push({neigh_row, neigh_col});
                    }
                }
            }
        }
        return res;
    }
};
//time:O(N)
//space:O(N)
/*
每个顶点都来个BFS？
从某个顶点1开始逐层往外扩散，这样遇到的第一个0就是最近的
但是这样每个顶点都要来个BFS，复杂度高

反过来对每一个0开始BFS扩散

1.所有0结点都存入队列
2.判断队首结点cur的四周四个结点是否在有效范围内
3.若有效，则比较该点neigh的值是否比cur+1大，大于的话就更新neigh，neigh=cur+1，！！！并将neigh推入队列！！！
因为a） cur=0 neigh=0，都是0，则continue
b）cur!=0,neigh=0,continue
c）cur=0 neigh!=0, 说明neigh本来就是1，则将neigh更新为距离1，即cur+1
d）cur!=0 neigh!=0,说明cur本身也是1，但现在已经更新为当前的最小距离了，则neigh应该以cur为基础，更新其距离值为cur+1

这个BFS并不是对每个0都全盘扩张，如果是这样，那么就和以1为结点的BFS一样了
★这里队列中的每个结点都是只向外扩散4个点来，更新这4个点的值，如果这4个点本身都是0，那么这个点的bfs也就结束了，也就是被剪枝了。
或者周围四个点的距离都是比当前点最多大1，那么该点也已经更新好了。
如果周围某个点neigh原来不为0（或者距离值偏大），则依据当前点的值来更新距离，同时下次以neigh为基础，来更新它周围的点
*/