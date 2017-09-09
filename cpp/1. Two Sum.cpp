/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
#include <vector>
#include <map>
class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::map<int, int> cache;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (cache.find(target - nums[i]) != cache.end())
            {
                return std::vector<int>{cache[target - nums[i]], i};
            }
            else
            {
                cache[nums[i]] = i;
            }
        }
        return std::vector<int>{-1, -1};
    }
};

//O(N)

//extension
/*
If there are duplicated elements, cache will be overwritten when scanned 
the same element in different positions. [3,2,2,4]->cache[2]=1->cache[2]=2
If output is the value, it's OK! while if it is index, it will be wrong;

*/