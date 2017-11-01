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
首位想接合并两个数组，排序
time:O((m+n)log(m+n))

solution 2
两个数组从头开始依次比较，相当于有序合并两个数组，再选取中间值即可。
time:O(m+n)
如果两个数组是没有排序的，那要先排序，退化为solution 1
time:O((m+n)log(m+n))

soultion 3
用multiset (rb tree)来排序（适用于没有排序的数组，已经排好序的数组效率没有solution2高）
1.两个数组都插入multiset 最优O(m+n)
2.取median
a) pop (m+n)/2次， O((m+n)log(m+n))。 总的O((m+n)log(m+n))
b) c++版本，用c++11的next，相当于遍历迭代器， O(m+n)。 总的O(m+n)
c) c++中用一个iterator指向median并不断update，取median的复杂度可以达到 O(log(m+n))。

solution 4
用两个priority_queue来处理，取median的复杂度为O(1)
但是维护priority_queue的复杂度 最优为O(m+n),平均为O((m+n)log(m+n))

solution 5
考虑median的意义是什么？是将数组分成等长的两部分。
所以将A和B分别分成等长的两部分
l= max(left(A),left(B))
r= min(right(A),right(B))
median = (l+r)/2
*/

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        //make sure nums2 is shorter
        if (m < n)
            return findMedianSortedArrays(nums2.nums1);
    }
};