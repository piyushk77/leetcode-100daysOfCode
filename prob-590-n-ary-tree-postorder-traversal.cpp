#include <vector>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
    vector<int> res;

public:
    void traverse(Node *node)
    {
        if (!node)
            return;
        for (auto x : node->children)
            traverse(x);
        res.push_back(node->val);
    }
    vector<int> postorder(Node *root)
    {
        traverse(root);
        return res;
    }
};