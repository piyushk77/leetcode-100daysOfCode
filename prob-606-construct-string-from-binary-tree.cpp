#include <string>
using namespace std;

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
    string preOrderString(TreeNode *node)
    {
        string str{to_string(node->val)};
        if (!node->left && !node->right)
            return str;
        else if (!node->left)
        {
            string temp{preOrderString(node->right)};
            str += "()(";
            str += temp;
            str += ")";
            return str;
        }
        else if (!node->right)
        {
            string temp{preOrderString(node->left)};
            str += "(";
            str += temp;
            str += ")";
            return str;
        }
        else
        {
            string temp1{preOrderString(node->left)};
            str += "(";
            str += temp1;
            str += ")(";
            string temp2{preOrderString(node->right)};
            str += temp2;
            str += ")";
            return str;
        }
    }
    string tree2str(TreeNode *root) { return preOrderString(root); }
};