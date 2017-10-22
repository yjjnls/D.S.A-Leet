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

    return BinarySearchRecursion(data, target, low, high);
}

int BinarySearchRecursion(std::vector<int> &data, int target, int low, int high)
{
    // recursion terminator
    if (low > high)
        return -1;

    // current level processing
    int mid = low + (high - low) >> 1;
    if (data[mid] == target)
        return mid;

    //drill down
    if (data[mid] < target)
        BinarySearchRecursion(data, target, mid + 1, high);
    else
        BinarySearchRecursion(data, target, low, mid - 1);
}