#include <cmath>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // Update the nodes for height
    int updateHeight(TreeNode *root)
    {
        if (!root)
            return 0;

        // Update the height of the left subtree
        int leftTree{updateHeight(root->left)};
        // Update the height of the right subtree
        int rightTree{updateHeight(root->right)};

        // Update the height of the current node
        root->val = max(leftTree, rightTree) + 1;

        return root->val;
    }

    int getMax(TreeNode *root)
    {
        if (!root)
            return 0;
        int leftHeight{}, rightHeight{};
        if (root->left)
            leftHeight = root->left->val;
        if (root->right)
            rightHeight = root->right->val;

        int currLen{leftHeight + rightHeight};

        // Get the maxdiameter from the leftTree and rightTree
        int leftD{}, rightD{};
        if (root->left)
            leftD = getMax(root->left);
        if (root->right)
            rightD = getMax(root->right);

        return max(currLen, max(leftD, rightD));
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        // Update the height of the tree
        updateHeight(root);
        // Get the diameter of the tree
        int diameter{getMax(root)};
        return diameter;
    }
};