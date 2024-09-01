#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        vector<vector<int>> res(m, vector<int>(n));
        const int len{static_cast<int>(original.size())};
        int i{};
        if (m * n != len)
            return {};
        for (auto &x : res)
        {
            for (int k{}; k < n && i < len; ++k, ++i)
                x[k] = original[i];
        }
        return res;
    }
};