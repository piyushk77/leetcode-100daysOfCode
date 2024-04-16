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
    TreeNode *addRow(TreeNode *node, int val, int depth, int currentDepth)
    {
        if (depth == 1)
        {
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = node;
            return newRoot;
        }
        if (currentDepth == depth - 1)
        {
            TreeNode *leftNode = new TreeNode(val, node->left, nullptr);
            TreeNode *rightNode = new TreeNode(val, nullptr, node->right);
            node->left = leftNode;
            node->right = rightNode;
            return nullptr;
        }
        else
        {
            if (node->left)
                addRow(node->left, val, depth, currentDepth + 1);
            if (node->right)
                addRow(node->right, val, depth, currentDepth + 1);
            return nullptr;
        }
    }
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        TreeNode *newRoot{addRow(root, val, depth, 1)};
        if (!newRoot)
            return root;
        else
            return newRoot;
    }
};