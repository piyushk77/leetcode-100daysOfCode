#include <vector>
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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if (nums.size() == 0)
            return nullptr;

        int index{}, max{};
        for (int i{}; i < nums.size(); ++i)
        {
            if (max < nums[i])
            {
                max = nums[i];
                index = i;
            }
        }
        auto start = nums.begin();
        auto end = nums.begin() + index;
        vector<int> leftSubarray(index);
        copy(start, end, leftSubarray.begin());

        int n{static_cast<int>(nums.size())};
        vector<int> rightSubarray(static_cast<int>(n - index - 1));
        if (n - index - 1)
        {
            start = nums.begin() + index + 1;
            end = nums.begin() + n;
            copy(start, end, rightSubarray.begin());
        }

        TreeNode *left = constructMaximumBinaryTree(leftSubarray);
        TreeNode *right = constructMaximumBinaryTree(rightSubarray);
        TreeNode *root = new TreeNode(max, left, right);

        return root;
    }
};