struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
    bool match(ListNode *currListNode, TreeNode *currTreeNode)
    {
        if (!currListNode && !currTreeNode)
            return true;
        if (!currListNode && currTreeNode)
            return true;
        if (!currListNode || !currTreeNode)
            return false;
        if (currListNode->val != currTreeNode->val)
            return false;
        return match(currListNode->next, currTreeNode->left) ||
               match(currListNode->next, currTreeNode->right);
    }
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        if (!root)
            return false;
        if (match(head, root))
            return true;
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};