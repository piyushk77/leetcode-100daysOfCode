#include <vector>
#include <stack>
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
    TreeNode *balanceTree(vector<int> nodes, int start, int end)
    {
        if (start > end)
            return nullptr;
        int mid{(start + end) / 2};
        TreeNode *root{new TreeNode(nodes[mid])};
        TreeNode *leftRoot{balanceTree(nodes, start, mid - 1)};
        TreeNode *rightRoot{balanceTree(nodes, mid + 1, end)};
        root->left = leftRoot;
        root->right = rightRoot;
        return root;
    }
    TreeNode *balanceBST(TreeNode *root)
    {
        // Extract the nodes in ascending order
        vector<int> nodes{};
        // Inorder traversal using stack
        stack<TreeNode *> s;
        TreeNode *currNode{root};
        while (!s.empty() || currNode)
        {
            while (currNode)
            {
                s.push(currNode);
                currNode = currNode->left;
            }
            // Pop the topmost element
            currNode = s.top();
            s.pop();
            nodes.push_back(currNode->val);
            currNode = currNode->right;
        }
        // Create a balanced binary search tree
        int n{static_cast<int>(nodes.size())};
        return balanceTree(nodes, 0, n - 1);
    }
};