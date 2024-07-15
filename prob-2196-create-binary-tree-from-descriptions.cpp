#include <unordered_map>
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
    void createTree(TreeNode *&node, unordered_map<int, vector<int>> &binMap)
    {
        if (binMap.find(node->val) != binMap.end())
        {
            vector<int> children{binMap[node->val]};
            if (binMap[node->val][0])
            {
                TreeNode *temp{new TreeNode(binMap[node->val][0])};
                node->left = temp;
                createTree(node->left, binMap);
            }
            if (binMap[node->val][1])
            {
                TreeNode *temp{new TreeNode(binMap[node->val][1])};
                node->right = temp;
                createTree(node->right, binMap);
            }
        }
    }
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        // create the binary tree map
        unordered_map<int, vector<int>> binMap;
        unordered_map<int, int> children;
        for (auto x : descriptions)
        {
            children[x[1]]++;
            if (binMap.find(x[0]) != binMap.end())
            {
                if (x[2])
                    binMap[x[0]][0] = x[1];
                else
                    binMap[x[0]][1] = x[1];
            }
            else
            {
                vector<int> temp{0, 0};
                if (x[2])
                    temp[0] = x[1];
                else
                    temp[1] = x[1];
                binMap.insert(make_pair(x[0], temp));
            }
        }

        // find the root node
        int rootNode{};
        for (auto x : descriptions)
            if (children.find(x[0]) == children.end())
            {
                rootNode = x[0];
                break;
            }

        TreeNode *root{new TreeNode(rootNode)};
        createTree(root, binMap);
        return root;
    }
};