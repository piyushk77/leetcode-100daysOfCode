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
    bool isPalindrome(ListNode *head)
    {
        vector<int> num;
        while (head)
        {
            num.push_back(head->val);
            head = head->next;
        }

        vector<int> rev;
        for (int i{static_cast<int>(num.size()) - 1}; i >= 0; --i)
        {
            rev.push_back(num[i]);
        }

        for (int i{}; i < num.size(); ++i)
        {
            if (num[i] != rev[i])
                return false;
        }
        return true;
    }
};