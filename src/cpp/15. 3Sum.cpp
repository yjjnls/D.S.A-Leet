/*
Given an array S of n integers, are there elements a, b, c in S such that a + b
+ c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
#include <common.hpp>
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i + 2 < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            int target = -nums[i];
            while (j < k)
            {
                if (nums[j] + nums[k] == target)
                {
                    res.push_back({nums[i], nums[j], nums[k]});

                    while (j < k && nums[j] == nums[j + 1])
                    {
                        ++j;
                    }
                    while (j < k && nums[k] == nums[k - 1])
                    {
                        --k;
                    }
                    ++j;
                    --k;
                }
                else if (nums[j] + nums[k] < target)
                {
                    ++j;
                }
                else
                {
                    --k;
                }
            }
        }
        return res;
    }
};

//time: O(N^2)
//space: O(1)