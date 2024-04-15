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
    int sumPath(TreeNode *node, int num)
    {
        if (node)
            num = num * 10 + node->val;
        if (!node->left && !node->right)
            return num;
        else if (node->left && node->right)
            return sumPath(node->left, num) + sumPath(node->right, num);
        else if (node->left)
            return sumPath(node->left, num);
        else
            return sumPath(node->right, num);
    }
    int sumNumbers(TreeNode *root) { return sumPath(root, 0); }
};