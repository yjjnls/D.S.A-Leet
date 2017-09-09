/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution
{
public:
    bool isValid(string s)
    {
        std::unordered_map<char, char> cache{{'(', ')'}, {'{', '}'}, {'[', ']'}};
        std::stack<char> store;
        for (int i = 0; i < s.size(); ++i)
        {
            if (cache.find(s[i]) != cache.end())
            {
                store.push(cache[s[i]]);
            }
            else
            {
                //"]", top() will report error
                if (!store.empty() && store.top() == s[i])
                {
                    store.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if (store.size() != 0)
        {
            return false;
        }
        return true;
    }
};

//time: O(N)
//space: O(1)