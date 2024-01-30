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
    bool findSum(TreeNode *node, int targetSum, int currentSum)
    {
        currentSum += node->val;
        if (!node->left && !node->right)
        {
            if (currentSum == targetSum)
                return true;
            else
                return false;
        }
        if (!node->left && node->right)
        {
            return (findSum(node->right, targetSum, currentSum));
        }
        else if (node->left && !node->right)
        {
            return (findSum(node->left, targetSum, currentSum));
        }
        else if (node->left && node->right)
        {
            return (findSum(node->left, targetSum, currentSum) ||
                    findSum(node->right, targetSum, currentSum));
        }
        return false;
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        return findSum(root, targetSum, 0);
    }
};