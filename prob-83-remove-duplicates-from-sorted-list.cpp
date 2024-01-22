struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void deleteRepeat(ListNode *node)
    {
        if (!node || !node->next)
            return;
        int currentValue{node->val};
        int nextValue{node->next->val};
        if (currentValue != nextValue)
        {
            deleteRepeat(node->next);
            return;
        }
        ListNode *tempNode{node->next};
        node->next = tempNode->next;
        deleteRepeat(node);
    }
    ListNode *deleteDuplicates(ListNode *head)
    {
        deleteRepeat(head);
        return head;
    }
};