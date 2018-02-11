/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/
#include <common.hpp>
class Solution3
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
        // ！！！最后一个数一定落在最后一个桶里面
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

        int prev_max = min_num;
        int gap = 0;
        // 遍历非空桶之间的gap，求最大值
        for (auto &bucket : buckets)
        {
            if (!bucket.used)
                continue;

            gap = std::max(gap, bucket.minval - prev_max);
            prev_max = bucket.maxval;
        }
        return gap;
    }
};

/*
solution 1
直接排序，然后遍历比较相邻数据的差距，求出最大值
time:O(NlogN)

solution 2
计数排序
先遍历求出最大值与最小值的差距k，创建数组（k个元素）
将所有数据插入到相应的位置，然后遍历数组，找到空隙最大的即可
time:O(N)
O(d*(n+r)) 其中，d 为位数，r 为基数，n 为原数组个数。
space:O(k) k>=N
！！！但是如果数据的间隙很大（1，2，10000）效率就不高
这里可以用bit compressed库，但在算法题里面就不太合适

solution 3
桶排序(在solution 2的基础上将分组的间隔扩大，提高space效率)
构建n个桶，每个桶记录最大值和最小值，遍历非空桶之间的gap即可
time：O(N)
space：O(N)

solution 4
基数排序 
 O(d⋅(n+k))≈O(n).
*/
//radix sort 记不住的
class Solution4
{
public:
    int maximumGap(vector<int> &nums)
    {
        if (nums.empty() || nums.size() < 2)
            return 0;

        int maxVal = *max_element(nums.begin(), nums.end());

        int exp = 1;   // 1, 10, 100, 1000 ...
        int radix = 10;// base 10 system

        vector<int> tmp(nums.size());
        vector<int> bucket(nums.begin(), nums.end());
        /* LSD Radix Sort */
        while (maxVal / exp > 0)
        {
            // 1.clear count
            vector<int> count(radix, 0);
            // 2.统计每个桶里面有多少个数
            // 对于当前第i个桶，0-i个桶的数总和即为，i桶中最后一个数应该排在第几位（在比较第k位时）
            for (int i = 0; i < bucket.size(); i++)
                count[(bucket[i] / exp) % 10]++;
            for (int i = 1; i < count.size(); i++)
                count[i] += count[i - 1];
            // 3.从后往前处理nums，判断其在count中的值，即为他实际应该排在第几位
            for (int i = bucket.size() - 1; i >= 0; i--)
                tmp[--count[(bucket[i] / exp) % 10]] = bucket[i];
            for (int i = 0; i < bucket.size(); i++)
                bucket[i] = tmp[i];

            exp *= 10;
        }

        int maxGap = 0;

        for (int i = 0; i < bucket.size() - 1; i++)
            maxGap = std::max(bucket[i + 1] - bucket[i], maxGap);

        return maxGap;
    }
};