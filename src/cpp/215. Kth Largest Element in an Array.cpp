/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/
#include<common.hpp>
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {

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

4. divide and conquer
to implement

*/