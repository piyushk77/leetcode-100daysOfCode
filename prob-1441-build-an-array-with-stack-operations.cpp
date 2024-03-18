#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        vector<string> res;
        int prev{};
        for (int i{}; i < target.size(); ++i)
        {
            if ((target[i] - prev - 1) == 0)
            {
                res.push_back("Push");
            }
            else
            {
                for (int k{1}; k <= (target[i] - prev - 1); ++k)
                {
                    res.push_back("Push");
                    res.push_back("Pop");
                }
                res.push_back("Push");
            }
            prev = target[i];
        }
        return res;
    }
};