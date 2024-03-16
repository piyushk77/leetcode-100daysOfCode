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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        vector<int> firstStack;
        vector<int> secondStack;
        while (l1)
        {
            firstStack.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            secondStack.push_back(l2->val);
            l2 = l2->next;
        }
        int carry{};
        ListNode *sumList{nullptr};
        while (firstStack.size() || secondStack.size())
        {
            int a{}, b{};
            if (firstStack.size())
            {
                a = firstStack.back();
                firstStack.pop_back();
            }
            if (secondStack.size())
            {
                b = secondStack.back();
                secondStack.pop_back();
            }
            int sum{a + b + carry};
            carry = sum / 10;
            sum = sum % 10;
            ListNode *node = new ListNode(sum);
            node->next = sumList;
            sumList = node;
        }
        if (carry)
        {
            ListNode *node = new ListNode(carry);
            node->next = sumList;
            sumList = node;
        }
        return sumList;
    }
};