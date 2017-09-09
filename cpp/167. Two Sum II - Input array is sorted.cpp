/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int low = 0;
        int high = numbers.size() - 1;
        int a = numbers[low];
        int b = numbers[high];
        while (low < high)
        {
            if (a + b == target)
            {
                break;
            }
            else if (a + b < target)
            {
                ++low;
                //!!!avoid get value every time
                a = numbers[low];
            }
            else
            {
                --high;
                b = numbers[high];
            }
        }
        return vector<int>{low + 1, high + 1};
    }
};

//O(N)
/*
* Input elements may be duplicated, but the answer can't be duplicated, weather the output is index or value.
* If there's more than one solution, just replace the `break` with `res.push_back({low+1,high+1})`
*
* If there's duplicated elements, the answer is also OK!
*/