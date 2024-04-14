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
    bool isLeaf(TreeNode *node)
    {
        if (!node->left && !node->right)
            return true;
        return false;
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (isLeaf(root))
            return 0;
        else if (!root->left)
            return sumOfLeftLeaves(root->right);
        else if (!root->right)
        {
            if (isLeaf(root->left))
                return root->left->val;
            else
                return sumOfLeftLeaves(root->left);
        }
        else
        {
            if (isLeaf(root->left))
                return root->left->val + sumOfLeftLeaves(root->right);
            else
                return sumOfLeftLeaves(root->left) +
                       sumOfLeftLeaves(root->right);
        }
    }
};