/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/
#include <common.hpp>
class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
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

*/