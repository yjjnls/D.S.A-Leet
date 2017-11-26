/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note: 
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?
*/
#include <common.hpp>
class Solution1
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        if (nums.empty() || k > nums.size())
        {
            return res;
        }
        for (int i = 0; i < nums.size() - k + 1; ++i)
        {
            int max_num = nums[i];
            for (int j = 1; j < k; ++j)
            {
                max_num = std::max(nums[i + j], max_num);
            }
            res.push_back(max_num);
        }
        return res;
    }
};

//time:O(K*N)
//space:O(1)
//solution1 brute force


/*
Solution2
1. i-> 0 ~ n-k+1
2. use a priority queue to store the k nums and get the max num(such like max top heap)
3. move i and update priority queue (add and delete)

time:O(N*logK) logK is the complexity of max top head, if use most optimized pq, it could be O(1)
space:O(K)

★★★★★the pq will store the nums within the window in order, 
and then you could also output the second max num within the window

the priority_queue in C++ doesn't support remove a certain element. 
So the solution below uses set to implement.
用优先队列或者红黑树来维护窗口
*/
class Solution2
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        std::multiset<int, std::greater<int>> window;
        if (nums.empty() || k > nums.size())
        {
            return res;
        }
        for (int i = 0; i < k; ++i)
        {
            window.insert(nums[i]);
        }
        res.push_back(*window.begin());
        for (int i = k; i < nums.size(); ++i)
        {
            window.erase(window.lower_bound(nums[i - k]));
            window.insert(nums[i]);
            res.push_back(*window.begin());
        }
        return res;
    }
};

/*
Solution3 (just remember and practice)
use a deque
1. i-> 0 ~ n-k+1
2. push the ★【index】 of the nums into deque orderly
3. get the max num and remain only the nums in the right of the max num and itself
4. move i and update the deque

★ ensure every loop of i, deque.front is the max number's index 

1->5
    1 <- 2 <- 3 <- 4 <- 5 <- push_back(new)
    👆                  👆
    front               back

deque.front <= i-k       deque.pop_front
while(nums[deque.back] < nums[i])     deque.pop_back  
deque.push_back(i)
res.push_back(nums[deque.front()])



time:O(N)
space:O(K)
*/
using std::deque;
class Solution3
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        deque<int> window_index;
        if (nums.empty() || k > nums.size())
        {
            return res;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (!window_index.empty() && window_index.front() <= (i - k))
            {
                window_index.pop_front();
            }
            while (!window_index.empty() &&
                   nums[window_index.back()] < nums[i])
            {
                window_index.pop_back();
            }
            window_index.push_back(i);
            if (i >= k - 1)
            {
                res.push_back(nums[window_index.front()]);
            }
        }
        return res;
    }
};