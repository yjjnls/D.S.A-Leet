/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/
#include <common.hpp>
class Solution
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


//这里不能用 mid*mid <= x
/*
也可以把int 换成double
但是while的比较条件就要变成 abs(data[mid]-target)<10^-5
*/