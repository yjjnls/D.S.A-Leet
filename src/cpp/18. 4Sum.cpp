/*
Given an array S of n integers, are there elements a, b, c, and d in S such that
a + b + c + d = target? Find all unique quadruplets in the array which gives the
sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/
#include <common.hpp>

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        if (nums.empty() || nums.size() < 4)
        {
            return res;
        }
        std::sort(nums.begin(), nums.end());
        int target2, sum, front, back;
        for (int i = 0; i < nums.size() - 3; ++i)
        {
            //skip duplicated element
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int j = i + 1; j < nums.size() - 2; ++j)
            {
                //j>i+1 is very important!!!!!!! if it's j>0, it's wrong
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                target2 = target - nums[i] - nums[j];
                front = j + 1;
                back = nums.size() - 1;
                while (front < back)
                {
                    sum = nums[front] + nums[back];
                    if (sum == target2)
                    {
                        res.push_back({nums[i], nums[j], nums[front], nums[back]});
                        while (front < back && nums[front] == nums[front + 1])
                        {
                            ++front;
                        }
                        while (front < back && nums[back] == nums[back - 1])
                        {
                            --back;
                        }
                        ++front;
                        --back;
                    }
                    else if (sum < target2)
                    {
                        ++front;
                    }
                    else
                    {
                        --back;
                    }
                }
            }
        }
        return res;
    }
};

//!!!discuss N sum method for python. practice and remember!!!

//time:O(N^3)
//space:O(1)
#ifdef USE_GTEST
TEST(DSA, 18_4Sum)
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    Solution s;
    vector<vector<int>> res = s.fourSum(nums, 0);
    vector<int> tmp1 = {-2, -1, 1, 2};
    vector<int> tmp2 = {-2, 0, 0, 2};
    vector<int> tmp3 = {-1, 0, 0, 1};
    vector<vector<int>> result = {tmp1, tmp2, tmp3};
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            ASSERT_TRUE(res[i][j] == result[i][j]);
        }
    }
}
#endif