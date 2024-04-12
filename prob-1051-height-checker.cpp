#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> expected{heights};
        sort(expected.begin(), expected.end());
        int count{};
        for (int i{}; i < heights.size(); ++i)
        {
            if (heights[i] != expected[i])
                ++count;
        }
        return count;
    }
};