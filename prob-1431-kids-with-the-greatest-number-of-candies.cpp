#include <vector>
using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int max{};
        for (auto x : candies)
        {
            if (max < x)
                max = x;
        }
        vector<bool> ans;
        for (auto x : candies)
        {
            if ((x + extraCandies) >= max)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};