#include <string>
#include <cmath>
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
    string getBinary(ListNode *node)
    {
        if (!node)
            return "";
        string bit{to_string(node->val)};
        return bit + getBinary(node->next);
    }
    int getDecimalValue(ListNode *head)
    {
        string binary{getBinary(head)};
        string revBinary{};
        for (auto x : binary)
        {
            revBinary = x + revBinary;
        }
        int num{};
        for (int i{}; i < revBinary.size(); ++i)
        {
            if (revBinary[i] == '1')
            {
                num += static_cast<int>(pow(2, i));
            }
        }
        return num;
    }
};