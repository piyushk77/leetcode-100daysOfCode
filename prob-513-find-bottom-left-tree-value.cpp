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
    vector<int> findBottom(TreeNode *node, int depth)
    {
        vector<int> data;
        // if node is a leaf node return the value of that node and depth as vector
        if (node->left == nullptr && node->right == nullptr)
        {
            data.push_back(depth);
            data.push_back(node->val);
            return data;
        }
        // else check if left of the current node is valid
        else if (node->left != nullptr)
        {
            // check if right node is valid
            if (node->right != nullptr)
            {
                // return the maximum depth of the findBottom(left, depth+1) and findBottom(right, depth+1)
                vector<int> leftData{findBottom(node->left, depth + 1)};
                vector<int> rightData{findBottom(node->right, depth + 1)};
                if (leftData[0] >= rightData[0])
                    return leftData;
                else
                    return rightData;
            }
            else
                return findBottom(node->left, depth + 1);
        }
        else
            return findBottom(node->right, depth + 1);
    }
    int findBottomLeftValue(TreeNode *root)
    {
        vector<int> data{findBottom(root, 1)};
        return data[1];
    }
};