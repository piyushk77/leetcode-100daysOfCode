#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int j{}, k{};
        bool positive{true};
        vector<int> res;
        for (int i{}; i < nums.size(); ++i)
        {
            int select{};
            // select the positive number in order
            if (positive)
            {
                while (j < nums.size() && nums[j] < 0)
                    ++j;
                positive = false;
                select = nums[j];
                ++j;
            }

            // select the negative number in order
            else
            {
                while (k < nums.size() && nums[k] > 0)
                    ++k;
                positive = true;
                select = nums[k];
                ++k;
            }
            res.push_back(select);
        }
        return res;
    }
};