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
    bool isEqual(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        else if (!p && q)
            return false;
        else if (p && !q)
            return false;

        if (p->left == nullptr && q->right == nullptr)
        {
            if (p->right == nullptr && q->left == nullptr)
            {
                if (p->val == q->val)
                {
                    return true;
                }
            }
            else if (p->right != nullptr && q->left != nullptr)
            {
                if (p->val == q->val)
                {
                    return isEqual(p->right, q->left);
                }
                else
                    return false;
            }
        }
        else if (p->right == nullptr && q->left == nullptr)
        {
            if (p->val == q->val)
            {
                return isEqual(p->left, q->right);
            }
            else
                return false;
        }

        if (p->val == q->val)
        {
            return isEqual(p->left, q->right) && isEqual(p->right, q->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode *root)
    {
        return isEqual(root->left, root->right);
    }
};