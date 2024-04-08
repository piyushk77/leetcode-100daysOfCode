#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> genSpiral(int start, int n)
    {
        if (n == 0)
            return {{}};
        else if (n == 1)
            return {{start}};
        vector<vector<int>> spiral(n, vector<int>(n, -1));
        // traverse right
        for (int i{}; i < n; ++i)
            spiral[0][i] = start++;
        // traverse down
        for (int i{1}; i < n; ++i)
            spiral[i][n - 1] = start++;
        // traverse left
        for (int i{n - 2}; i >= 0; --i)
            spiral[n - 1][i] = start++;
        // traverse up
        for (int i{n - 2}; i >= 1; --i)
            spiral[i][0] = start++;

        vector<vector<int>> miniSpiral{genSpiral(start, n - 2)};

        for (int i{1}; i < n - 1; ++i)
        {
            for (int j{1}; j < n - 1; ++j)
            {
                spiral[i][j] = miniSpiral[i - 1][j - 1];
            }
        }

        return spiral;
    }
    vector<vector<int>> generateMatrix(int n) { return genSpiral(1, n); }
};