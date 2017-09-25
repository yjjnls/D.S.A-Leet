/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode *toBST(ListNode *head, ListNode *tail)
    {
        //1.recursion terminator
        ListNode *slow = head;
        ListNode *fast = head;
        if (head == tail)
        {
            return NULL;
        }

        //2.current level processing
        while (fast != tail && fast->next != tail)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode *root = new TreeNode(slow->val);

        //3.drill down
        root->left = toBST(head, slow);
        root->right = toBST(slow->next, tail);

        return root;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        return toBST(head, NULL);
    }
};

//time:O(N^2)


//solution2
/*
the elements are sorted in ascending order.
inorder traversal of the BST -> ascending order

inorder()
{
    if root
        inorder(root.left)
        traverse_path(root)
        inorder(root.right)
}
*/
class Solution
{
public:
    TreeNode *toBST(int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }
        int mid = start + (end - start) / 2;
        //这里是start而不是0~mid-1
        TreeNode *left = toBST(start, mid - 1);

        TreeNode *root = new TreeNode(curr_node_->val);
        root->left = left;
        curr_node_ = curr_node_->next;

        root->right = toBST(mid + 1, end);
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        curr_node_ = head;

        ListNode *tmp = head;
        int size = 0;
        while (tmp != NULL)
        {
            tmp = tmp->next;
            ++size;
        }

        return toBST(0, size - 1);
    }

private:
    ListNode *curr_node_;
};

//time:O(N)


//extension
//if input is an array sorted in ascending order?

class Solution
{
public:
    TreeNode *toBST(int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }
        int mid = start + (end - start) / 2;
        //这里是start而不是0~mid-1
        TreeNode *left = toBST(start, mid - 1);

        TreeNode *root = new TreeNode((*num_)[pos_]);
        root->left = left;
        ++pos_;

        root->right = toBST(mid + 1, end);
        return root;
    }
    TreeNode *sortedListToBST(vector<int> &num)
    {
        if (num.empty())
        {
            return NULL;
        }
        num_ = &num;
        int size = num.size();
        return toBST(0, size - 1);
    }

private:
    vector<int> *num_;
    int pos_ = 0;
};