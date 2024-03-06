#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        int marking{1'000'00 + 1};
        ListNode *node{head};
        while (node)
        {
            if (node->val == marking)
                return true;
            node->val = marking;
            node = node->next;
        }
        return false;
    }
};