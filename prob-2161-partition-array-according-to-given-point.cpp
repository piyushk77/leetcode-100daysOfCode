#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        vector<int> less, more, equal;
        for (auto x : nums)
        {
            if (x < pivot)
                less.push_back(x);
            else if (x > pivot)
                more.push_back(x);
            else
                equal.push_back(x);
        }
        vector<int> res{less};
        for (auto x : equal)
            res.push_back(x);
        for (auto x : more)
            res.push_back(x);
        return res;
    }
};