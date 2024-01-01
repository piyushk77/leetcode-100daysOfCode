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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        bool sumComplete{};

        ListNode *l1_currentNode = l1;
        ListNode *l2_currentNode = l2;
        ListNode *listSum = nullptr;
        ListNode *listSumHead = nullptr;

        int carry{};
        while (!sumComplete)
        {
            if (!l1_currentNode && !l2_currentNode && !carry)
                break;

            int tempSum{};
            int numL1{}, numL2{};
            int digit{};
            if (l1_currentNode)
                numL1 = l1_currentNode->val;
            if (l2_currentNode)
                numL2 = l2_currentNode->val;

            tempSum = numL1 + numL2 + carry;
            digit = tempSum % 10;
            carry = tempSum / 10;

            ListNode *newListSumNode = new ListNode;
            newListSumNode->val = digit;
            newListSumNode->next = listSum;
            listSum = newListSumNode;

            if (l1_currentNode)
                l1_currentNode = l1_currentNode->next;
            if (l2_currentNode)
                l2_currentNode = l2_currentNode->next;
        }

        // Reverse the order of listSum
        ListNode *zeroNode = nullptr;
        ListNode *firstNode = listSum;
        ListNode *secondNode = listSum->next;
        ListNode *tempNode = nullptr;
        while (secondNode)
        {
            tempNode = secondNode->next;
            firstNode->next = zeroNode;
            secondNode->next = firstNode;
            zeroNode = firstNode;
            if (!tempNode)
            {
                listSum = secondNode;
                break;
            }

            firstNode = secondNode;
            secondNode = tempNode;
        }

        return listSum;
    }
};