#include <vector>
#include <climits>
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
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        ListNode *curr{head};
        ListNode *prev{};
        vector<int> criticals{};
        int i{}, k{};
        while (curr)
        {
            if (!prev || !curr->next)
                ;
            else if ((prev->val < curr->val) && (curr->val > curr->next->val) || (prev->val > curr->val) && (curr->val < curr->next->val))
            {
                criticals.push_back(i);
                ++k;
            }
            prev = curr;
            curr = curr->next;
            ++i;
        }
        if (k < 2)
            return {-1, -1};
        int minDistance{INT_MAX}, maxDistance{};
        for (int j{1}; j < k; ++j)
            if (minDistance > (criticals[j] - criticals[j - 1]))
                minDistance = criticals[j] - criticals[j - 1];
        maxDistance = criticals[k - 1] - criticals[0];
        return {minDistance, maxDistance};
    }
};