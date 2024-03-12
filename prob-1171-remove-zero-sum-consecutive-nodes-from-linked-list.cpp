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
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode *startList{head};
        ListNode *topNode{head};
        ListNode *prevTopNode{head};
        while (topNode)
        {
            ListNode *currentNode{topNode};
            int sum{};
            bool flag{};
            while (currentNode)
            {
                sum += currentNode->val;
                if (!sum)
                {
                    flag = true;
                    if (topNode == startList)
                    {
                        startList = currentNode->next;
                        topNode = startList;
                        break;
                    }
                    prevTopNode->next = currentNode->next;
                    topNode = currentNode->next;
                    break;
                }
                currentNode = currentNode->next;
            }
            if (!flag)
            {
                prevTopNode = topNode;
                topNode = topNode->next;
            }
        }
        return startList;
    }
};