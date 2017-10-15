/*
Given a binary tree, return the level order traversal of its nodes' values. 
(ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

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
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        //1.terminator
        if (root == NULL)
            return res;
        //2.init container
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            vector<int> curr_level;
            int cur_size = q.size();

            for (int i = 0; i < cur_size; ++i)
            {
                //3.pop node from container
                TreeNode *node = q.front();
                q.pop();
                //4.process current node
                curr_level.push_back(node->val);
                //5.push related nodes to container
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }
            //6.other work
            res.push_back(curr_level);
        }

        return res;
    }
};

/*
time:O(N)
1. BFS
这里while中用了一个for将当前一层的node一次性处理了，与模版稍有不同
2. DFS
★ DFS也能写
*/

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {

        //1.terminator
        if (root == NULL)
            return res;
        //2.init container
        stack<TreeNode *> s;
        s.push(root);

        while (!s.empty())
        {
            //3.pop node for
        }
    }
    void _def(TreeNode *node, level)
    {
        //recursion reminator
        if (node == NULL)
            return;
        //current level process
        if (res_.size() < level + 1)
            res_.push_back(vector<int>);
        res_[level].push_back(node->val);

        //drill down
        _def(node->left, level + 1);
        _def(node->right, level + 1);
    }

private:
    vector<vector<int>> res_;
}