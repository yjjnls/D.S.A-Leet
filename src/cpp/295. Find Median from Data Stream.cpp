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

#include <common.hpp>
namespace solution3
{
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
}
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

/*
solution 1
先存入n个元素，再【整体】排序，然后求中位数
time:O(n⋅log(n))时间复杂度太高
space:O(n)
每次取都将所有元素sort一遍


solution 2
每个元素都插入的时候就排序（用插入排序），单次插入时间复杂度为O(n)
time:O(n)
space:O(n)
与solution1不同的是，soultion把所有元素一起排序，而soultion2将每一个新元素插入到对应位置，
【先二分查找O（logn），再insert，后续元素要移位，可能要O（n），一共是O（n）】
但是站在整体元素角度考虑，时间复杂度会是O（n^2）,如果这里用一个logn的排序（BST），那么时间复杂度是和solution1一样的

个人认为solution 1和solution 2没太大区别（站在整体角度看）
---------------------------------------
solution 3
用两个heap，或者priority queue
具体过程这里不描述了，可以参考 480 sliding window median
单次时间复杂度为O（logn），插入一个数据后，经过堆调整时间复杂度为O（logn），取median为O(1)
但是整体时间复杂度为O(nlogn)
space:O(n)
!!!用两个堆的话虽然和solution 2中的BST排序求中值时间复杂度一样，但是用堆取median的时间最短O（1），而且适合海量数据!!!


solution 4
用multiset和two pointers
如果是用平衡BST来存储数据，那么median一般在root结点或者root的children。
因此可以用multiset和两个指针（迭代器）来维护
插入数据num时，分为以下3种：
1.multiset为空，lo和hi都指向num
2.multiset有奇数个数字，现在lo和hi都指向同一个数字，之后两个指针要分开
  num< lo时，lo--
  num>=hi时，hi++（这里也即num==lo==hi的情况）
3.multiset有偶数个数字，插入num后，lo和high要指向同一个数字。
  lo<=num<hi lo=hi=num  即lo++ hi--（这里num==lo是，是插入到lo的右边，所以插入后在lo和hi的中间）
  num< lo lo++
  num>=hi hi--
！！！由于这里c++的特性，若插入的数字相同，那么是插入在所有相同数字之后，
time：O(logn)+O(1)
*/
namespace solution5
{
    class MedianFinder
    {
        multiset<int> data;
        multiset<int>::iterator lo_median, hi_median;

    public:
        MedianFinder()
            : lo_median(data.end())
            , hi_median(data.end())
        {
        }

        void addNum(int num)
        {
            const size_t n = data.size();// store previous size

            data.insert(num);// insert into multiset

            if (!n)
            {
                // no elements before, one element now
                lo_median = hi_median = data.begin();
            }
            else if (n & 1)
            {
                // odd size before (i.e. lo == hi), even size now (i.e. hi = lo + 1)

                if (num < *lo_median)// num < lo
                    --lo_median;
                else            // num >= hi
                    ++hi_median;// insertion at end of equal range
            }
            else
            {
                // even size before (i.e. hi = lo + 1), odd size now (i.e. lo == hi)

                if (num >= *lo_median && num < *hi_median)
                {
                    ++lo_median;// num in between lo and hi
                    --hi_median;
                }
                else if (num >= *hi_median)// num inserted after hi
                    ++lo_median;
                else            // num <= lo < hi
                    --hi_median;// insertion at end of equal range spoils lo
            }
        }

        double findMedian()
        {
            return (*lo_median + *hi_median) * 0.5;
        }
    };
}