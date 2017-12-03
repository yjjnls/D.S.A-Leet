#include <common.hpp>
ListNode *create_list(vector<int> nums)
{
    ListNode dummy(0);
    ListNode *node = &dummy;
    for (int num : nums)
    {
        node->next = new ListNode(num);
        node = node->next;
    }

    return dummy.next;
}
void free_list(ListNode *l)
{
    while (l != NULL)
    {
        ListNode *tmp = l;
        l = l->next;
        delete tmp;
    }
}
void compare_lists(ListNode *l1, ListNode *l2)
{
    while (l1 != NULL && l2 != NULL)
    {
        ASSERT_TRUE(l1->val == l2->val);
        l1 = l1->next;
        l2 = l2->next;
    }
    ASSERT_TRUE(l1 == NULL && l2 == NULL);
}