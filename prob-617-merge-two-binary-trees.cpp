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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
            return nullptr;
        TreeNode *mergeRoot{new TreeNode()};
        if (root1 && root2)
        {
            mergeRoot->val = root1->val + root2->val;
            mergeRoot->left = mergeTrees(root1->left, root2->left);
            mergeRoot->right = mergeTrees(root1->right, root2->right);
        }
        else if (!root1)
            mergeRoot = root2;
        else if (!root2)
            mergeRoot = root1;
        return mergeRoot;
    }
};