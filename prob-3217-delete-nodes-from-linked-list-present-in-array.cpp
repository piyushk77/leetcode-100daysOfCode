#include <vector>
#include <unordered_set>
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
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        unordered_set<int> numSet;
        for (auto x : nums)
            numSet.insert(x);
        ListNode *newHead{head};
        while (newHead && numSet.find(newHead->val) != numSet.end())
        {
            ListNode *temp{newHead};
            newHead = newHead->next;
            temp->next = nullptr;
            delete temp;
        }
        ListNode *prev{newHead};
        ListNode *curr{prev->next};
        while (curr)
        {
            if (numSet.find(curr->val) != numSet.end())
            {
                ListNode *temp{curr};
                curr = curr->next;
                prev->next = curr;
                temp->next = nullptr;
                delete temp;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        return newHead;
    }
};