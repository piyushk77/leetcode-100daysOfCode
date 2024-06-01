#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned,
                            TreeNode *target)
    {
        if (!original)
            return original;
        queue<TreeNode *> q;
        queue<TreeNode *> copyQ;
        q.push(original);
        copyQ.push(cloned);
        while (!q.empty())
        {
            TreeNode *currOrg{q.front()};
            q.pop();
            TreeNode *currClon{copyQ.front()};
            copyQ.pop();
            if (currOrg == target)
                return currClon;
            if (currOrg->left)
            {
                q.push(currOrg->left);
                copyQ.push(currClon->left);
            }
            if (currOrg->right)
            {
                q.push(currOrg->right);
                copyQ.push(currClon->right);
            }
        }
        return nullptr;
    }
};