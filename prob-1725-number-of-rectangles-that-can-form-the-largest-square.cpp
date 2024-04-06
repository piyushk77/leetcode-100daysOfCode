#include <vector>
using namespace std;

class Solution
{
public:
    int countGoodRectangles(vector<vector<int>> &rectangles)
    {
        int maxLen{};
        for (auto x : rectangles)
        {
            int len{(x[0] < x[1] ? x[0] : x[1])};
            if (maxLen < len)
                maxLen = len;
        }
        int count{};
        for (auto x : rectangles)
        {
            if (maxLen == (x[0] < x[1] ? x[0] : x[1]))
                ++count;
        }
        return count;
    }
};