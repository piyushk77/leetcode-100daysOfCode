#include <stack>
#include <string>
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
private:
    stack<pair<int, string>> startPath, endPath;
    int start, end;

public:
    bool checkStartPath(TreeNode *node, string direction)
    {
        if (!node)
            return false;
        if (node->val == start)
        {
            startPath.push({node->val, direction});
            return true;
        }
        bool left{checkStartPath(node->left, "L")};
        if (left)
        {
            startPath.push({node->val, direction});
            return true;
        }
        bool right{checkStartPath(node->right, "R")};
        if (right)
        {
            startPath.push({node->val, direction});
            return true;
        }
        return false;
    }
    bool checkEndPath(TreeNode *node, string direction)
    {
        if (!node)
            return false;
        if (node->val == end)
        {
            endPath.push({node->val, direction});
            return true;
        }
        bool left{checkEndPath(node->left, "L")};
        if (left)
        {
            endPath.push({node->val, direction});
            return true;
        }
        bool right{checkEndPath(node->right, "R")};
        if (right)
        {
            endPath.push({node->val, direction});
            return true;
        }
        return false;
    }

    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        start = startValue;
        end = destValue;
        checkStartPath(root, "X");
        checkEndPath(root, "X");
        while (!startPath.empty() && !endPath.empty() && startPath.top() == endPath.top())
        {
            startPath.pop();
            endPath.pop();
        }
        string directions{};
        while (!startPath.empty())
        {
            directions += "U";
            startPath.pop();
        }
        while (!endPath.empty())
        {
            directions += endPath.top().second;
            endPath.pop();
        }
        return directions;
    }
};