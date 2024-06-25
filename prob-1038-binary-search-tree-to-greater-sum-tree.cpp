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
    int toGst(TreeNode *node, int sum)
    {
        int rightSum{}, leftSum{};
        node->val += sum;
        if (node->right)
            node->val += toGst(node->right, sum);
        if (node->left)
            return toGst(node->left, node->val) + node->val - sum;
        return node->val - sum;
    }
    TreeNode *bstToGst(TreeNode *root)
    {
        toGst(root, 0);
        return root;
    }
};