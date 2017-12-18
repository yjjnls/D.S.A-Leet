/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/
#include <common.hpp>
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int left = 0, right = nums.size() - 1;
        while (true)
        {
            int pos = partition(nums, left, right);
            if (pos == k - 1)
                return nums[pos];
            if (pos > k - 1)
                right = pos - 1;
            else
                left = pos + 1;
        }
    }

private:
    int partition(vector<int> &nums, int left, int right)
    {
        int pivot = nums[left];
        int l = left + 1, r = right;
        while (l <= r)
        {
            if (nums[l] < pivot && nums[r] > pivot)
                std::swap(nums[l++], nums[r--]);
            if (nums[l] >= pivot)
                l++;
            if (nums[r] <= pivot)
                r--;
        }
        std::swap(nums[left], nums[r]);
        return r;
    }
};

/*

1. brute force
1st,2nd->kth
time:O(n*k)

2. sort
time: O(nlogn)

3. priority_queue
pop O(logn)
time:O(n+k*logn)
space:O(n)

or time:O((n+k)*logn)

4. divide and conquer(quick select)
1）每次迭代选取一个轴点pivot（这里每次都选取最左边的点），将数组分为两部分
    左半部分左右数据<=pivot 有半部分所有数据>=pivot，pivot所在位置为pos，pivot就是第pos+1大的数据
2） 根据pos与k-1的大小来分而治之


T(n) = T(n/2) + O(n)
time:O(n)
如果要像快排那样，每次都要将两边都进行下一次递归，那么时间复杂度就是
T(n) = 2T(n/2) + O(n)
time:O(nlogn)
*/
#ifdef USE_GTEST
TEST(DSA, 215_kth_largest_element_in_an_array)
{
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    Solution s;
    double res = s.findKthLargest(nums, 2);

    ASSERT_TRUE(res == 5);
}
#endif