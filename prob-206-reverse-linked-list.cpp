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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *revList{nullptr};
        while (head)
        {
            ListNode *node{revList};
            revList = head;
            head = head->next;
            revList->next = node;
        }
        return revList;
    }
};