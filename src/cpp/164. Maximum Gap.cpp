/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/
#include <common.hpp>
class Solution
{
    struct Bucket
    {
        bool used = false;
        int minval = std::numeric_limits<int>::max();// same as INT_MAX
        int maxval = std::numeric_limits<int>::min();// same as INT_MIN
    };

public:
    int maximumGap(vector<int> &nums)
    {
        if (nums.empty() || nums.size() < 2)
            return 0;

        int min_num = *std::min_element(nums.begin(), nums.end());
        int max_num = *std::max_element(nums.begin(), nums.end());

        // n个元素，分为n-1个区间，n个桶
        int bucketSize = std::max(1, (max_num - min_num) / ((int)nums.size() - 1));
        int bucketNum = (max_num - min_num) / bucketSize + 1;
        vector<Bucket> buckets(bucketNum);

        // 构造桶，每个桶记录最大值和最小值
        for (auto &num : nums)
        {
            // 落在哪一个桶
            int bucketIdx = (num - min_num) / bucketSize;
            buckets[bucketIdx].used = true;
            buckets[bucketIdx].minval = std::min(num, buckets[bucketIdx].minval);
            buckets[bucketIdx].maxval = std::max(num, buckets[bucketIdx].maxval);
        }
    }
};

/*
solution 1
直接排序，然后遍历比较相邻数据的差距，求出最大值
time:O(logN)

solution 2
计数排序
先遍历求出最大值与最小值的差距k，创建数组（k个元素）
将所有数据插入到相应的位置，然后遍历数组，找到空隙最大的即可
time:O(N)
！！！但是如果数据的间隙很大（1，2，10000）效率就不高
这里可以用bit compressed库，但在算法题里面就不太合适

solution 3
桶排序


*/
class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
    }
};