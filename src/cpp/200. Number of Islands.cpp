/*
Given a 2d grid map of '1's (land) and '0's (water), 
count the number of islands. An island is surrounded 
by water and is formed by connecting adjacent lands 
horizontally or vertically. You may assume all four 
edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
*/

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        int row = grid.size();
        int col = -1;
        for (int i = 0; i < row; ++i)
        {
            col = grid[i].size();
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '1')
                {
                    ++count;
                    flood_fill(grid, i, j);
                }
            }
        }
        return count;
    }
    void flood_fill(vector<vector<char>> &grid, int i, int j)
    {
        if (!is_valid(grid, i, j))
            return;
        //DFS
        grid[i][j] = '0';
        flood_fill(grid, i - 1, j);
        flood_fill(grid, i + 1, j);
        flood_fill(grid, i, j - 1);
        flood_fill(grid, i, j + 1);
    }

    bool is_valid(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 ||
            i == grid.size() ||
            j < 0 ||
            j == grid[i].size() ||
            grid[i][j] == '0')
            return false;
        return true;
    }
};
//time:O(N)
/*
flood fill
1. i j遍历grid
2. 当前结点为1表示新岛， count+1
3. 淹没当前岛

淹没的过程就相当于遍历一个全是1的图

1. DFS

2. BFS

*/
void flood_fill_bfs(vector<vector<char>> &grid, int i, int j)
{
}