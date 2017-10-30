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

typedef std::unordered_set<string> Hash;

class Solution
{
public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        //init terminator
        if (bank.empty())
            return -1;
        if (start == end)
            return 0;

        Hash dict(bank.begin(), bank.end());
        //end不在bank中，无效
        if (!dict.count(end))
            return -1;

        Hash bset, eset, *set1, *set2;
        bset.insert(start);
        eset.insert(end);
        int step = 0, gene_string_size = start.size();

        while (!bset.empty() && !eset.empty())
        {
            //set1指向元素少的hash
            if (bset.size() <= eset.size())
                set1 = &bset, set2 = &eset;
            else
                set2 = &bset, set1 = &eset;
            Hash tmp;
            step++;
            for (auto itr = set1->begin(); itr != set1->end(); ++itr)
            {
                for (int i = 0; i < gene_string_size; ++i)
                {
                    string dna = *itr;
                    for (auto g : string("ATGC"))
                    {
                        dna[i] = g;
                        if (set2->count(dna))
                            return step;
                        if (dict.count(dna))
                        {
                            tmp.insert(dna);
                            dict.erase(dna);
                        }
                    }
                }
            }
            *set1 = tmp;
        }
        return -1;
    }
};


class Solution
{
public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        queue<string> BSQ;
        unordered_set<string> bset(bank.begin(), bank.end());
        int res = 0;

        if (!bset.count(end))
            return -1;
        BSQ.push(start);
        bset.insert(start);
        while (!BSQ.empty())
        {
            int n = BSQ.size();
            for (int i = 0; i < n; ++i)
            {
                string fr = BSQ.front();
                BSQ.pop();
                if (fr == end)
                    return res;
                else
                {
                    bset.erase(fr);//so as not to find it self
                    for (int i = 0; i < fr.size(); ++i)
                    {
                        char tmp = fr[i];
                        for (auto c : string{"ATCG"})
                        {
                            fr[i] = c;
                            if (bset.count(fr))
                            {
                                BSQ.push(fr);
                                bset.erase(fr);
                            }
                        }
                        fr[i] = tmp;
                    }
                }
            }
            ++res;
        }
        return -1;
    }
};