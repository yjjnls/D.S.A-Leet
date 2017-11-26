/*
Given a triangle, find the minimum path sum from top to bottom. Each step you
may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is
the total number of rows in the triangle.
*/
//[[-1],[2,3],[1,-1,-3]]
#include <common.hpp>
class Solution1
{
public:
    int nextfloor(vector<vector<int>> &triangle, int n, int cur_level, int pre_pos)
    {
        vector<int> &floor = triangle[cur_level];
        if (cur_level == n - 1)
        {
            return std::min(floor[pre_pos], floor[pre_pos + 1]);
        }
        int rc1 = nextfloor(triangle, n, cur_level + 1, pre_pos) + floor[pre_pos];
        int rc2 = nextfloor(triangle, n, cur_level + 1, pre_pos + 1) + floor[pre_pos + 1];
        return std::min(rc1, rc2);
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return triangle[0][0];
        }
        return nextfloor(triangle, n, 1, 0) + triangle[0][0];
    }
};
//这是自上而下的递归
//time:O(2^N)
//space:

/*up to down (recursion)(soulution above)
f(1)=tri[1,1]
f(2)=min(tri[2,1],tri[2,2])+f(1) 
f(3)=min(tri[3,i],tri[3,i+1])+f(2)


*/

/*
down to up (1D DP)

minpath[k][i] = min( minpath[k+1][i], minpath[k+1][i+1]) + triangle[k][i];

since the row minpath[k+1] would be useless after minpath[k] is computed, we can simply set minpath as a 1D array, and iteratively update itself:

For the kth level:
minpath[i] = min( minpath[i], minpath[i+1]) + triangle[k][i]; 

*/

class Solution2
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> minlen(triangle.back());
        for (int layer = n - 2; layer >= 0; layer--)// For each layer
        {
            for (int i = 0; i <= layer; i++)// Check its every 'node'
            {
                // Find the lesser of its two children, and sum the current value in the triangle with it.
                minlen[i] = std::min(minlen[i], minlen[i + 1]) + triangle[layer][i];
            }
        }
        return minlen[0];
    }
};

//time:O(N)
//space:O(1)?O(N)

//★if use recursion, the time complexity will be O(2^N)