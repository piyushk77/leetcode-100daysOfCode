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
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *node{head};
        ListNode *mergeList = new ListNode();
        ListNode *prevNode = mergeList;
        while (node)
        {
            if (node->val == 0)
            {
                node = node->next;
                int sum{};
                while (node && node->val)
                {
                    sum += node->val;
                    node = node->next;
                }
                if (!node)
                    break;
                ListNode *mergeNode = new ListNode(sum);
                prevNode->next = mergeNode;
                prevNode = mergeNode;
            }
        }
        return mergeList->next;
    }
};