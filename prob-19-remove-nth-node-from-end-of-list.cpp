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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *topBead{head};
        ListNode *bottomBead{head};
        int stretch{};
        while (stretch < n)
        {
            bottomBead = bottomBead->next;
            ++stretch;
        }
        if (bottomBead == nullptr)
            return topBead->next;
        while (bottomBead->next != nullptr)
        {
            topBead = topBead->next;
            bottomBead = bottomBead->next;
        }
        // Deleting the nth node
        ListNode *nth{topBead->next};
        topBead->next = nth->next;
        return head;
    }
};