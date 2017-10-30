/*
A gene string can be represented by an 8-character long string, with choices from "A", "C", "G", "T".

Suppose we need to investigate about a mutation (mutation from "start" to "end"), where ONE mutation 
is defined as ONE single character changed in the gene string.

For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.

Also, there is a given gene "bank", which records all the valid gene mutations. A gene must be in the 
bank to make it a valid gene string.

Now, given 3 things - start, end, bank, your task is to determine what is the minimum number of mutations 
needed to mutate from "start" to "end". If there is no such a mutation, return -1.

Note:

Starting point is assumed to be valid, so it might not be included in the bank.
If multiple mutations are needed, all mutations during in the sequence must be valid.
You may assume start and end string is not the same.
Example 1:

start: "AACCGGTT"
end:   "AACCGGTA"
bank: ["AACCGGTA"]

return: 1
Example 2:

start: "AACCGGTT"
end:   "AAACGGTA"
bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]

return: 2
Example 3:

start: "AAAAACCC"
end:   "AACCCCCC"
bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]

return: 3
*/

#include <common.hpp>
using std::queue;
using std::unordered_set;
class Solution
{
public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        // terminator
        unordered_set<string> dict(bank.begin(), bank.end());
        if (!dict.count(end))
            return -1;
        // init container
        queue<string> toVisit;
        int res = 0;

        toVisit.push(start);
        // dict.insert(start);

        while (!toVisit.empty())
        {
            int n = toVisit.size();
            for (int i = 0; i < n; ++i)
            {
                // pop node from container
                string curr_gen = toVisit.front();
                toVisit.pop();
                // process current node
                if (curr_gen == end)
                    return res;
                else
                {
                    // dict.erase(curr_gen);//so as not to find it self
                    for (int i = 0; i < curr_gen.size(); ++i)
                    {
                        char tmp = curr_gen[i];
                        // push related nodes to container
                        for (auto c : string{"ATCG"})
                        {
                            curr_gen[i] = c;
                            if (dict.count(curr_gen))
                            {
                                toVisit.push(curr_gen);
                                dict.erase(curr_gen);
                            }
                        }
                        curr_gen[i] = tmp;
                    }
                }
            }
            ++res;
        }
        return -1;
    }
};

/*
bfs 逐层向外变换，第一次变换到目标时，一定是最短路径。
*/