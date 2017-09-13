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
class Solution
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

//time:O(2^N)
//space:

/*
f(1)=tri[1,1]
f(2)=min(tri[2,1],tri[2,2])+f(1) 
f(3)=min(tri[3,i],tri[3,i+1])+f(2)


*/