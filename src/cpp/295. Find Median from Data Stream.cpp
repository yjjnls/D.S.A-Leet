/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
*/


class MedianFinder
{
public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        // 这里形式上也可以简化一些，直接push到largeElements中
        // 并始终保持largeElements比smallElements个数 >= 1
        if (smallElements.empty() && largeElements.empty())
        {
            largeElements.push(num);
            return;
        }

        if (num >= largeElements.top())
            largeElements.push(num);
        else
            smallElements.push(num);

        //adjust heap
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

    double findMedian()
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
    std::priority_queue<int> smallElements;                           //maxHeap
    std::priority_queue<int, vector<int>, greater<int>> largeElements;//minHeap
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */