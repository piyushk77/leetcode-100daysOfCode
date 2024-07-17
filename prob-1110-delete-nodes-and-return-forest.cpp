#include <vector>
#include <unordered_map>
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
    void cleanForest(TreeNode *node, TreeNode *parent, char dir)
    {
        if (!node)
            return;
        cleanForest(node->left, node, 'L');
        cleanForest(node->right, node, 'R');
        if (node->val == -1)
        {
            if (dir == 'L')
                parent->left = nullptr;
            else
                parent->right = nullptr;
            delete node;
        }
    }
    void getSubForest(TreeNode *node, TreeNode *parent, vector<TreeNode *> &deforest)
    {
        if (!node)
            return;
        if (parent->val == -1 && node->val != -1)
        {
            deforest.push_back(node);
        }
        getSubForest(node->left, node, deforest);
        getSubForest(node->right, node, deforest);
    }
    void createMap(TreeNode *node, unordered_map<int, TreeNode *> &forest)
    {
        if (!node)
            return;
        forest.insert({node->val, node});
        createMap(node->left, forest);
        createMap(node->right, forest);
    }
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        // create the node map of the forest
        unordered_map<int, TreeNode *> forest;
        createMap(root, forest);
        // mark delete the target nodes
        for (auto x : to_delete)
            forest[x]->val = -1;
        vector<TreeNode *> deforest;
        TreeNode *parent{new TreeNode(-1)};
        parent->left = root;
        getSubForest(root, parent, deforest);

        // clean deleted nodes
        cleanForest(root, parent, 'L');
        return deforest;
    }
};