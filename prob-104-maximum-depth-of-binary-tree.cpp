#include <cmath>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    int depth(TreeNode *node, int currentDepth)
    {
        if (!node)
        {
            return currentDepth;
        }
        if (!node->left && !node->right)
        {
            return currentDepth;
        }
        return max(depth(node->left, currentDepth + 1),
                   depth(node->right, currentDepth + 1));
    }
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return depth(root, 1);
    }
};