/*
Median is the middle value in an ordered integer list. 
If the size of the list is even, there is no middle value. 
So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Given an array nums, there is a sliding window of size k 
which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. 
Each time the sliding window moves right by one position. 
Your job is to output the median array for each window in the original array.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Median
---------------               -----
[1  3  -1] -3  5  3  6  7       1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7       3
 1  3  -1  -3 [5  3  6] 7       5
 1  3  -1  -3  5 [3  6  7]      6
Therefore, return the median sliding window as [1,-1,-1,3,5,6].

Note: 
You may assume k is always valid, ie: k is always smaller than input array's size for non-empty array.
*/
#include <common.hpp>
class Solution1
{
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        vector<double> res;
        std::multiset<int> window;
        if (nums.empty() || k > nums.size())
        {
            return res;
        }
        for (int i = 0; i < k; ++i)
        {
            //O(logk)
            window.insert(nums[i]);
        }
        res.push_back(getMedian(window, k));
        for (int i = k; i < nums.size(); ++i)
        {
            window.erase(window.lower_bound(nums[i - k]));
            window.insert(nums[i]);
            res.push_back(getMedian(window, k));
        }
        return res;
    }

    double getMedian(std::multiset<int> &window, int k)
    {
        //(k+1)/2
        if (k % 2 != 0)
        {
            //O(k),对vector等能随机访问的是O(1)，其余的是O(n)
            auto it = std::next(window.begin(), (k - 1) / 2);
            return *it;
        }
        else
        {
            int mid1 = *std::next(window.begin(), k / 2 - 1);
            int mid2 = *std::next(window.begin(), k / 2);
            return (static_cast<double>(mid1) + static_cast<double>(mid2)) / 2;
        }
        return 0;
    }
};

//time:O(N*K)
//space:O(K)
/*
用multiset其实就是排序的方法
另一种方法就是两个堆来实现
*/
/*
the question is that the how to fast to get median? use two heaps?
用两个优先队列来求中值，复杂度也是O(NlogK)

1. remove element，每次窗口移动时，窗口最左边的数从包含它的堆中去除。
2. add element，窗口最右端新的数插入堆中。如果该数大于minHeap（大于中值的数）的root，则插入minHeap；否则插入maxHeap。（一开始可以默认加入maxHeap）
3. adjust heap，调整minHeap与maxHeap，使它们的大小之差<=1。大于1时就把堆顶元素吐给另一个堆
4. get median，取中值，只需要两个堆的root求平均，或者直接去元素多的那个堆的root即可。

c++版本 remove element操作无法实现！！！！！！！！！！！
*/

class Solution2
{
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        largeElements.push(nums[0]);
        vector<double> res;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (i >= k)
                remove_element(nums[k - i]);
            else
                continue;

            add_element(nums[k]);

            adjust_heap();

            double mid_val = get_median();
            res.push_back(mid_val);
        }
        return res;
    }
    void remove_element(int data)
    {
        //!!!这里c++的priority_queue不提供删除某个元素的操作，只能手动写，但是现实内存超标
        if (data >= largeElements.top())
        {
            vector<int> tmp;
            while (largeElements.top() != data)
            {
                tmp.push_back(largeElements.top());
                largeElements.pop();
            }
            largeElements.pop();
            for (auto it : tmp)
                largeElements.push(it);
        }
        else
        {
            vector<int> tmp;
            while (smallElements.top() != data)
            {
                tmp.push_back(smallElements.top());
                smallElements.pop();
            }
            smallElements.pop();
            for (auto it : tmp)
                smallElements.push(it);
        }
    }
    void add_element(int data)
    {
        if (data >= largeElements.top())
            largeElements.push(data);
        else
            smallElements.push(data);
    }
    void adjust_heap()
    {
        int m = largeElements.size();
        int n = smallElements.size();

        while (abs(m - n) > 1)
        {
            if (m - 1 > n)
            {
                int tmp = largeElements.top();
                largeElements.pop();
                smallElements.push(tmp);
            }
            if (n - 1 > m)
            {
                int tmp = smallElements.top();
                smallElements.pop();
                largeElements.push(tmp);
            }

            m = largeElements.size();
            n = smallElements.size();
        }
    }
    double get_median()
    {
        int m = largeElements.size();
        int n = smallElements.size();
        if (m == n)
        {
            return (double(largeElements.top()) + double(smallElements.top())) / 2;
        }
        if (m > n)
            return largeElements.top();

        if (m < n)
            return smallElements.top();
    }

private:
    std::priority_queue<int> smallElements;                                //maxHeap
    std::priority_queue<int, vector<int>, std::greater<int>> largeElements;//minHeap
};

TEST(DSA, 480_Sliding_Window_Median)
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> results = {1.00000, -1.00000, -1.00000, 3.00000, 5.00000, 6.00000};
    Solution1 s1;
    vector<double> res1 = s1.medianSlidingWindow(nums, 3);
    for (int i = 0; i < 6; ++i)
        ASSERT_TRUE(abs(res1[i] - results[i]) < 0.00001);

    results = {0.00000, 1.00000, 1.00000, 4.00000, 5.50000};
    Solution1 s2;
    vector<double> res2 = s2.medianSlidingWindow(nums, 4);
    for (int i = 0; i < 5; ++i)
        ASSERT_TRUE(abs(res2[i] - results[i]) < 0.00001);

    Solution1 s3;
    vector<int> tmp;
    vector<double> res3 = s3.medianSlidingWindow(tmp, 4);
    ASSERT_TRUE(res3.empty());
}