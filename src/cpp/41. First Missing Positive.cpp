/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/


/* solution
N nums, best is [1~N]-->N+1
otherwise, output<=N
traverse 1~N+1, ouput the first integer not in the given array(store in set or map)
*/
#include <common.hpp>
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int max_num = nums.size() + 1;
        //hash_set is not supported here, it's not in C++ standard
        std::unordered_set<int> num_set;
        //O(N)
        for (int i = 0; i < nums.size(); ++i)
        {
            num_set.insert(nums[i]);
        }
        //O(N)
        for (int i = 1; i < max_num; ++i)
        {
            //O(1)
            if (num_set.find(i) == num_set.end())
            {
                return i;
            }
        }
        return max_num;
    }
};

//time-->O(N)
//memory-->O(1) set.size=max_num

//other format
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        //nums[5]=2-->swap(nums[1],nums[5])
        //O(N)
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i + 1 == nums[i])
                continue;
            int x = nums[i];
            while (x >= 1 && x <= nums.size() && x != nums[x - 1])
            {
                swap(x, nums[x - 1]);
            }
        }
        //O(N)
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i + 1 != nums[i])
                return i + 1;
        }
        return nums.size() + 1;
    }
};