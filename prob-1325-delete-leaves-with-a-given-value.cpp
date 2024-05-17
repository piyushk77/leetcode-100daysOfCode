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
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        TreeNode *leftChild{root->left};
        TreeNode *rightChild{root->right};

        // check if the current node is a leaf node
        if (!leftChild && !rightChild && root->val == target)
        {
            root = nullptr;
            return root;
        }

        // check if the left child is a leaf node
        if (leftChild)
            if (!leftChild->left && !leftChild->right &&
                leftChild->val == target)
            {
                root->left = nullptr;
            }

        // check if the right child is a leaf node
        if (rightChild)
            if (!rightChild->left && !rightChild->right &&
                rightChild->val == target)
            {
                root->right = nullptr;
            }

        if (root->left)
            removeLeafNodes(root->left, target);
        if (root->right)
            removeLeafNodes(root->right, target);

        // check again if the current node became the leaf node
        if (!root->left && !root->right && root->val == target)
        {
            root = nullptr;
            return root;
        }

        // check if the left child is a leaf node
        if (leftChild)
            if (!leftChild->left && !leftChild->right &&
                leftChild->val == target)
            {
                root->left = nullptr;
            }

        // check if the right child is a leaf node
        if (rightChild)
            if (!rightChild->left && !rightChild->right &&
                rightChild->val == target)
            {
                root->right = nullptr;
            }

        return root;
    }
};