#include <vector>
using namespace std;

class Solution
{
public:
    int numberOfEmployeesWhoMetTarget(vector<int> &hours, int target)
    {
        int count{};
        for (auto x : hours)
        {
            if (x >= target)
                ++count;
        }
        return count;
    }
};