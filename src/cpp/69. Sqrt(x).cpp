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
    }
};

/*
也可以把int 换成double
但是while的比较条件就要变成 abs(data[mid]-target)<10^-5
*/

int BinarySearch(std::vector<int> &data, int target)
{
    // termiantor
    if (data.empty())
        return -1;//或者返回其他的

    int low = 0;
    int high = data.size() - 1;
    int mid = low + (high - low) >> 1;

    // important 1
    while (low <= high)
    {
        // important 2


        if (data[mid] == target)
            return mid;
        else if (data[mid] < target)
            // important 1
            low = mid + 1;
        else
            // important 1
            high = mid - 1;
    }

    return -1;
}