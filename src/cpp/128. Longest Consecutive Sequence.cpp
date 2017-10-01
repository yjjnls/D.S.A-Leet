/*
Given an unsorted array of integers, find the length of the longest consecutive
elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

*/

class Solution
{
public:
    int longestConsecutive(vector<int> &num)
    {
        std::unordered_set<int> record(num.begin(), num.end());
        int res = 0;
        for (int n : num)
        {
            if (record.find(n) == record.end())
            {
                continue;
            }
            record.erase(n);
            int prev = n - 1, next = n + 1;
            while (record.find(prev) != record.end())
            {
                record.erase(prev--);
            }
            while (record.find(next) != record.end())
            {
                record.erase(next++);
            }
            res = std::max(res, next - prev - 1);
        }
        return res;
    }
};

//time:O(N)? I think it's O(N^2)★★★★
//space:O(1)

//The problem only wants the length, if wants the detail subarray
//It can be done with 1d dynamic programming
//1.sort the array
//2.get the longest increaset subarray