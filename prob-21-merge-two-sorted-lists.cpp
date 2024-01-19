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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1 || !list2)
        {
            if (list1)
                return list1;
            else
                return list2;
        }
        ListNode *head1{list1};
        ListNode *head2{list2};
        ListNode *topNode{list1};
        ListNode *prevHead1{nullptr};
        while (head1 && head2)
        {
            if (head2->val < head1->val)
            {
                if (!prevHead1)
                {
                    ListNode *temp{head2->next};
                    head2->next = head1;
                    prevHead1 = head2;
                    head2 = temp;
                    topNode = prevHead1;
                    continue;
                }
                else
                {
                    ListNode *temp{prevHead1->next};
                    prevHead1->next = head2;
                    head2 = head2->next;
                    prevHead1 = prevHead1->next;
                    prevHead1->next = temp;
                    continue;
                }
            }
            else
            {
                prevHead1 = head1;
                head1 = head1->next;
            }
        }

        if (!head1 && head2)
        {
            prevHead1->next = head2;
        }

        return topNode;
    }
};