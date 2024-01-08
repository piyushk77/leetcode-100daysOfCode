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
    int findRangeSum(TreeNode *node, int low, int high)
    {
        if (node->val >= low && node->val <= high)
        {
            if (!node->left && !node->right)
                return node->val;
            else if (node->left && !node->right)
            {
                return node->val + findRangeSum(node->left, low, high);
            }
            else if (!node->left && node->right)
            {
                return node->val + findRangeSum(node->right, low, high);
            }
            else
            {
                return node->val + findRangeSum(node->left, low, high) + findRangeSum(node->right, low, high);
            }
        }
        else if (node->val < low)
        {
            if (!node->left && !node->right)
                return 0;
            else if (node->right)
            {
                return findRangeSum(node->right, low, high);
            }
        }
        else
        {
            if (!node->left && !node->right)
                return 0;
            else if (node->left)
            {
                return findRangeSum(node->left, low, high);
            }
        }
        return 0;
    }
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int sum{findRangeSum(root, low, high)};
        return sum;
    }
};