/*
Given a sorted array, remove the duplicates in place such that each element appear only once and 
return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. 
It doesn't matter what you leave beyond the new length.
*/
#include <common.hpp>
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        int i = 0;
        for (int j = 1; j < nums.size(); ++j)
        {
            if (nums[j] != nums[i])
            {
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }
};

//time:O(N)
//space:O(1)