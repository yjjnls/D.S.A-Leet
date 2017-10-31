/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
*/
#include <common.hpp>
using std::queue;
using std::unordered_set;
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        // terminator
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord))
            return 0;

        // init container
        queue<string> toVisit;
        int res = 1;

        toVisit.push(beginWord);
        while (!toVisit.empty())
        {
            int n = toVisit.size();
            for (int i = 0; i < n; ++i)
            {
                // pop node from container
                string curr_word = toVisit.front();
                toVisit.pop();

                // process current node
                if (curr_word == endWord)
                    return res;
                else
                {
                    for (int i = 0; i < curr_word.size(); ++i)
                    {
                        char tmp = curr_word[i];
                        // push related nodes to container
                        for (int idx = 0; idx < 26; ++idx)
                        {
                            curr_word[i] = 'a' + idx;
                            if (dict.count(curr_word))
                            {
                                toVisit.push(curr_word);
                                dict.erase(curr_word);
                            }
                        }
                        curr_word[i] = tmp;
                    }
                }
            }
            ++res;
        }
        return 0;
    }
};