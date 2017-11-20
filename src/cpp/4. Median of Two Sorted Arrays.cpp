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
class Solution3
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
//O((m+n)log(m+n))
/*
solution 1
首位想接合并两个数组，排序
time:O((m+n)log(m+n))

solution 2
两个数组从头开始依次比较，相当于有序合并两个数组，再选取中间值即可。
time:O(m+n)
如果两个数组是没有排序的，那要先排序，退化为solution 1
time:O((m+n)log(m+n))

solution 3
用multiset (rb tree)来排序（适用于没有排序的数组，已经排好序的数组效率没有solution2高）
1.两个数组都插入multiset 最优O(m+n)，这里的最优是指类似于priority_queue那种情况，但一般的multiset是O((m+n)log(m+n))
2.取median
a) pop (m+n)/2次， O((m+n)log(m+n))。 总的O((m+n)log(m+n))
b) c++版本，用c++11的next，相当于遍历迭代器， O(m+n)。 总的O((m+n)log(m+n))
c) c++中用一个iterator指向median并不断update，取median的复杂度可以达到 O(log(m+n))。（答案暂时找不到了）

solution 4
用两个priority_queue来处理，取median的复杂度为O(1)，该操作效率最高！！！与solution 3的区别是solution 3只用一棵树来排序
但是维护priority_queue的复杂度 最优为O(m+n),平均为O((m+n)log(m+n))，看是否要弹出，用什么级别的priority queue等
感觉适用于海量数据


solution 5
考虑median的意义是什么？是将数组分成等长的两部分。
所以将A和B分别分成等长的两部分
l= max(left(A),left(B))
r= min(right(A),right(B))
median = (l+r)/2

--->FOR SINGLE ARRAY!
"if we cut the sorted array to two halves of EQUAL LENGTHS, then
median is the AVERAGE OF Max(lower_half) and Min(upper_half)"
[2 3 / 5 7]
[2 3 (4/4) 5 7](奇数个)
index L = (N-1)/2, and R is at N/2

--->FOR TWO ARRAYS!
上述例子正好是max(l1,l2)<= min(r1,r2)，所以l1,l2能代表lower_half，r1,r2能代表upper_half
但是当max(l1,l2)> min(r1,r2)时，情况就不是这样了
[2 3 / 5 7]
[4 8 / 9 11]
correct: [2 3 4 5 / 7 8 9 11]
可以看到这种情况下，合并数组后的分界线并不在l1,l2,r1,r2中
Similar to the one-array problem, we need to find a cut that divides the two arrays each into two halves such that
!!!"any number in the two left halves" <= "any number in the two right halves".
[2 3 5 / 7]
[4 / 8 9 11]

最终的效果应该是两个数组合并后有个cut，像下面这样
[1 1 1 1 1/1 2 3 4 5]
但是为了在两个分离的数组中表示这个cut，做下面的一个填充
A1: [# 1 # 2 # 3 # 4 # 5 #]
A2: [# 1 # 1 # 1 # 1 #]
这样A1和A2的新长度分别为2N1+1 2N2+2，对于单个数组，填充后的长度为2N+1，cut的位置应该在N
合并之后的长度为2N1+2N2+2，cut的位置应该在N1+N2
从另一个角度说就是c1+c2=cut=N1+N2，满足这个条件，就可以把两个数组分成两半，保证左右个数和相等。例如c2=2，c1=7
[# 1 # 2 # 3 # (4/4) # 5 #]    
[# 1 / 1 # 1 # 1 #] 
然后能够获得
L1 = A1[(C1-1)/2]; R1 = A1[C1/2];
L2 = A2[(C2-1)/2]; R2 = A2[C2/2];
由于L1 <= R1 and L2 <= R2，所以只要满足L1 <= R2 and L2 <= R1.  
*/

class Solution5
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        //make sure nums2 is shorter
        if (m < n)
            return findMedianSortedArrays(nums2, nums1);

        int lo = 0, hi = n * 2;
        while (lo <= hi)
        {
            int mid2 = (lo + hi) / 2;// Try Cut 2
            int mid1 = m + n - mid2; // Calculate Cut 1 accordingly

            double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1 - 1) / 2];// Get L1, R1, L2, R2 respectively
            double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2 - 1) / 2];
            double R1 = (mid1 == m * 2) ? INT_MAX : nums1[(mid1) / 2];
            double R2 = (mid2 == n * 2) ? INT_MAX : nums2[(mid2) / 2];

            if (L1 > R2)
                lo = mid2 + 1;// A1's lower half is too big; need to move C1 left (C2 right)
            else if (L2 > R1)
                hi = mid2 - 1;// A2's lower half too big; need to move C2 left.
            else
                return (std::max(L1, L2) + std::min(R1, R2)) / 2;// Otherwise, that's the right cut.
        }
        return -1;
    }
};

//the solution below is wrong
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        int l1 = 0, l2 = 0, r1 = 0, r2 = 0;
        if (m > 0)
        {
            l1 = nums1[(m - 1) / 2];
            r1 = nums1[m / 2];
        }
        if (n > 0)
        {
            l2 = nums2[(n - 1) / 2];
            r2 = nums2[n / 2];
        }

        int l = std::max(l1, l2);
        int r = std::min(r1, r2);
        double res = (double(l) + double(r)) / 2;

        return res;
    }
};
/*
Input:
[]
[1]
Output: 0.50000
Expected: 1.00000
*/