/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums
being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

*/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 2)
        {
            return nums.size();
        }
        int i = 2;
        for (int j = i + 1; j < nums.size(); ++j)
        {
            if (nums[j] > nums[i - 2])
            {
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};

//time:O(N)
//space:O(1)

int removeDuplicates(vector<int> &nums)
{
    int i = 0;
    for (int n : nums)
        if (i < 2 || n > nums[i - 2])
            nums[i++] = n;
    return i;
}