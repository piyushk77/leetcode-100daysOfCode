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
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *firstNode{head};
        ListNode *secondNode{head->next};
        firstNode->next = secondNode->next;
        secondNode->next = firstNode;
        ListNode *tempNode{swapPairs(firstNode->next)};
        firstNode->next = tempNode;
        return secondNode;
    }
};