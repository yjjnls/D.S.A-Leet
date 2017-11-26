/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/
#include <common.hpp>
class Solution1
{
public:
    int mySqrt(int x)
    {
        if (x < 0)
            return -1;
        if (x == 0)
            return 0;

        int low = 1;
        int high = x;
        int res;

        while (low <= high)
        {
            int mid = low + ((high - low) >> 1);

            if (mid <= x / mid)
            {
                low = mid + 1;
                res = mid;
            }
            else
                high = mid - 1;
        }

        return res;
    }
};
//time:O(log n)

//这里不能用 mid*mid <= x
/*
也可以把int 换成double
但是while的比较条件就要变成 abs(data[mid]-target)<10^-5

solution 2
还可以用牛顿迭代法
！！！！知道还可以用牛顿迭代法来求解，并且能写出来，那么会加分
*/

/*
f(n+1)=(f(n) + x/f(n))/2
*/

class Solution2
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;

        double res = x;
        double delta = 0.00001;

        while (abs(res * res - x) > delta)
            res = (res + x / res) / 2;

        return res;
    }
};