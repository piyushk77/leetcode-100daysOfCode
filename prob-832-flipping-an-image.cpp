#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image)
    {
        vector<vector<int>> flippedInverted;
        int n{static_cast<int>(image.size())};
        for (auto x : image)
        {
            vector<int> row;
            for (int i{n - 1}; i >= 0; --i)
            {
                int bit{};
                if (!x[i])
                    bit = 1;
                row.push_back(bit);
            }
            flippedInverted.push_back(row);
        }
        return flippedInverted;
    }
};