#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> distinctDifferenceArray(vector<int> &nums)
    {
        const int SIZE{50};
        vector<int> diff;
        for (int i{}; i < nums.size(); ++i)
        {
            vector<int> leftHash(SIZE + 1);
            for (int j{}; j <= i; ++j)
                ++leftHash[nums[j]];
            vector<int> rightHash(SIZE + 1);
            for (int j{i + 1}; j < nums.size(); ++j)
                ++rightHash[nums[j]];
            int left{}, right{};
            for (auto x : leftHash)
                if (x)
                    ++left;
            for (auto x : rightHash)
                if (x)
                    ++right;
            diff.push_back(left - right);
        }
        return diff;
    }
};