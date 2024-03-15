#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> straightTriangle;
        vector<int> invertedTriangle;
        int n{static_cast<int>(nums.size())};
        int prod{1};
        for (int i{}; i < n - 1; ++i)
        {
            prod *= nums[i];
            straightTriangle.push_back(prod);
        }
        prod = 1;
        for (int i{n - 1}; i > 0; --i)
        {
            prod *= nums[i];
            invertedTriangle.push_back(prod);
        }
        vector<int> res;
        res.push_back(invertedTriangle.back());
        for (int i{}; i < n - 2; ++i)
        {
            res.push_back(straightTriangle[i] * invertedTriangle[n - 3 - i]);
        }
        res.push_back(straightTriangle.back());
        return res;
    }
};