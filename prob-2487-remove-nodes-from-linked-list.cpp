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
    ListNode *removeNodes(ListNode *head)
    {
        vector<int> listNodes;
        ListNode *node{head};
        while (node)
        {
            listNodes.push_back(node->val);
            node = node->next;
        }
        int len{static_cast<int>(listNodes.size())};
        int max{};
        vector<int> suffixMax;
        for (int i{len - 1}; i >= 0; --i)
        {
            suffixMax.push_back(max);
            if (max < listNodes[i])
                max = listNodes[i];
        }

        // Begin deletion
        ListNode *newHead;
        ListNode *prev{nullptr};
        node = head;
        while (node)
        {
            if (node->val < suffixMax[--len])
            {
                if (!prev)
                {
                    node = node->next;
                    newHead = node;
                    continue;
                }
                prev->next = node->next;
                delete node;
                node = prev->next;
            }
            else
            {
                prev = node;
                node = node->next;
            }
        }

        return newHead;
    }
};