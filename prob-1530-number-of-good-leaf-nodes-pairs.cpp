#include <iostream>
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
    int count;

public:
    vector<vector<int>> compCount(TreeNode *node, int distance)
    {
        if (!node)
            return {{10000, 10000}};
        if (!node->left && !node->right)
            return {{node->val, 0}};
        vector<vector<int>> resLeft{compCount(node->left, distance)};
        vector<vector<int>> resRight{compCount(node->right, distance)};
        int l{static_cast<int>(resLeft.size())};
        int r{static_cast<int>(resRight.size())};
        for (int i{}; i < l; ++i)
        {
            if (resLeft[i][1] + 1 + resRight[0][1] + 1 > distance)
                break;
            for (int j{}; j < r; ++j)
            {
                if (resLeft[i][1] + 1 + resRight[j][1] + 1 <= distance)
                    ++count;
            }
        }
        int i{}, j{};
        int k{};
        vector<vector<int>> res(l + r, vector<int>());
        while (i < l || j < r)
        {
            if (i < l && j < r)
            {
                if (resLeft[i][1] <= resRight[j][1])
                {
                    resLeft[i][1]++;
                    res[k] = resLeft[i];
                    ++k;
                    ++i;
                }
                else
                {
                    resRight[j][1]++;
                    res[k] = resRight[j];
                    ++k;
                    ++j;
                }
            }
            else if (i < l)
            {
                resLeft[i][1]++;
                res[k] = resLeft[i];
                ++k;
                ++i;
            }
            else if (j < r)
            {
                resRight[j][1]++;
                res[k] = resRight[j];
                ++k;
                ++j;
            }
        }
        return res;
    }

    int countPairs(TreeNode *root, int distance)
    {
        count = 0;
        compCount(root, distance);
        return count;
    }
};