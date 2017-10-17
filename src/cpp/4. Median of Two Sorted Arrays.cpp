/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/
#include <common.hpp>
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        std::multiset<int> cache;
        for (auto it : nums1)
        {
            cache.insert(it);
        }
        for (auto it : nums2)
        {
            cache.insert(it);
        }
        int k = nums1.size() + nums2.size();
        if (k % 2 != 0)
        {
            auto it = std::next(cache.begin(), (k - 1) / 2);
            return *it;
        }
        else
        {
            int mid1 = *std::next(cache.begin(), k / 2 - 1);
            int mid2 = *std::next(cache.begin(), k / 2);
            return (static_cast<double>(mid1) + static_cast<double>(mid2)) / 2;
        }
        return 0;
    }
};

/*
solution 1
合并两个数组，排序
time:O((m+n)log(m+n))

soultion 2
multiset (rb tree)
*/