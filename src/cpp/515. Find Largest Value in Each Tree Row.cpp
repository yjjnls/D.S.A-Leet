/*
You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <common.hpp>
class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> res;
        //1.teminator
        if (root == NULL)
            return res;

        //2.init container
        std::queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int curr_size = q.size();
            //current level processing
            int cur_max = INT_MIN;
            for (int i = 0; i < curr_size; ++i)
            {
                //3.pop node from container
                TreeNode *node = q.front();
                q.pop();

                //4.process current node
                cur_max = node->val > cur_max ? node->val : cur_max;

                //5.push related nodes to container
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }
            res.push_back(cur_max);
        }
        return res;
    }
};
//time:O(N)

//dfs和bfs都能做
//dfs (recursion)
class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        if (root == NULL)
            return res;

        largestValues_DFS(root, 0);

        return res;
    }

    void largestValues_DFS(TreeNode *root, int level)
    {
        //1.recursion terminator
        if (root == NULL)
            return;

        //2.current level processing
        if (res.size() <= level)
            res.push_back(root->val);
        else if (res[level] < root->val)
            res[level] = root->val;

        //3.drill down
        largestValues_DFS(root->left, level + 1);
        largestValues_DFS(root->right, level + 1);
    }

private:
    vector<int> res;
};
