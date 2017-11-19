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
time:O(logN)

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

*/
class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        if (nums.empty() || nums.size() < 2)
            return 0;

        int maxVal = *max_element(nums.begin(), nums.end());

        int exp = 1;   // 1, 10, 100, 1000 ...
        int radix = 10;// base 10 system

        vector<int> aux(nums.size());

        /* LSD Radix Sort */
        while (maxVal / exp > 0)
        {// Go through all digits from LSD to MSD
            vector<int> count(radix, 0);

            for (int i = 0; i < nums.size(); i++)// Counting sort
                count[(nums[i] / exp) % 10]++;

            for (int i = 1; i < count.size(); i++)// you could also use partial_sum()
                count[i] += count[i - 1];

            for (int i = nums.size() - 1; i >= 0; i--)
                aux[--count[(nums[i] / exp) % 10]] = nums[i];

            for (int i = 0; i < nums.size(); i++)
                nums[i] = aux[i];

            exp *= 10;
        }

        int maxGap = 0;

        for (int i = 0; i < nums.size() - 1; i++)
            maxGap = max(nums[i + 1] - nums[i], maxGap);

        return maxGap;
    }
};