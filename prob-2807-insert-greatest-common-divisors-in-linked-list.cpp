#include <algorithm>
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
    int gcd(int x, int y)
    {
        if (x == 0 || y == 0)
            return 0;
        int maximum{max(x, y)};
        int minimums{min(x, y)};
        if (maximum % minimums == 0)
            return minimums;
        return gcd(maximum % minimums, minimums);
    }
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        ListNode *node{head};
        while (node)
        {
            if (node->next == nullptr)
            {
                node = node->next;
                continue;
            }
            int currentVal{node->val};
            int nextVal{node->next->val};
            ListNode *newNode{new ListNode(gcd(currentVal, nextVal))};
            ListNode *temp{node->next};
            node->next = newNode;
            newNode->next = temp;
            node = temp;
        }
        return head;
    }
};