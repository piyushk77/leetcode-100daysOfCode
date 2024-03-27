#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int numOfPairs(vector<string> &nums, string target)
    {
        int count{};
        for (int i{}; i < nums.size(); ++i)
        {
            for (int j{}; j < nums.size(); ++j)
            {
                if (i == j)
                    continue;
                if (nums[i] + nums[j] == target)
                    ++count;
            }
        }
        return count;
    }
};