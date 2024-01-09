#include <vector>
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
    vector<int> leafSequence(TreeNode *root)
    {
        if (!root->left && !root->right)
        {
            return {root->val};
        }
        else if (root->left && !root->right)
        {
            return leafSequence(root->left);
        }
        else if (!root->left && root->right)
        {
            return leafSequence(root->right);
        }
        else
        {
            vector<int> leftNodes{leafSequence(root->left)};
            vector<int> rightNodes{leafSequence(root->right)};
            leftNodes.insert(leftNodes.end(), rightNodes.begin(), rightNodes.end());
            return leftNodes;
        }

        return {};
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> leafSeq1{leafSequence(root1)};
        vector<int> leafSeq2{leafSequence(root2)};

        if (leafSeq1.size() != leafSeq2.size())
            return false;

        for (int i{}; i < leafSeq1.size(); ++i)
            if (leafSeq1[i] != leafSeq2[i])
                return false;
        return true;
    }
};