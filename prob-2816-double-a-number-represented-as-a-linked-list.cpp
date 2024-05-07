#include <vector>
using namespace std;

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
    ListNode *doubleIt(ListNode *head)
    {
        // Traverse the linked list and store each node in a vector
        ListNode *node{head};
        vector<int> nodeArr;
        while (node)
        {
            nodeArr.push_back(node->val);
            node = node->next;
        }
        // Reverse traverse the vector and double each node and add any carry
        // sum
        int len{static_cast<int>(nodeArr.size())};
        int carry{};
        for (int i{len - 1}; i >= 0; --i)
        {
            nodeArr[i] = nodeArr[i] * 2 + carry;
            carry = nodeArr[i] / 10;
            nodeArr[i] %= 10;
        }

        // create a new linked list from the vector
        ListNode *numDouble{nullptr};
        for (int i{len - 1}; i >= 0; --i)
        {
            ListNode *newNode = new ListNode(nodeArr[i], numDouble);
            numDouble = newNode;
        }
        if (carry)
        {
            ListNode *newNode = new ListNode(carry, numDouble);
            numDouble = newNode;
        }
        return numDouble;
    }
};