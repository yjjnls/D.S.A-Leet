/*
Given an array with n objects colored red, white or blue, sort them so that
objects of the same color are adjacent, with the colors in the order red, white
and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white,
and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite
array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0, mid = 0, high = nums.size() - 1;
        //!!!when mid>high break
        while (mid <= high)
        {
            if (nums[mid] == 1)
            {
                ++mid;
            }
            else if (nums[mid] == 0)
            {
                std::swap(nums[low], nums[mid]);
                ++low;
                ++mid;
            }
            else
            {
                std::swap(nums[mid], nums[high]);
                --high;
            }
        }
    }
};

//time:O(N)
//space:O(1)

/*
    1 0 2 2 1 0
    ^         ^
    L         H
    M

    M=1
    M++

    M=0
    swap(L,M)
    M++ L++

    M=2
    swap(M,H)
    H--
*/