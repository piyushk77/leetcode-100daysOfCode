#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        string binNum{};
        for (int i{}; i < nums.size(); ++i)
        {
            if (nums[i][i] == '0')
                binNum += '1';
            else
                binNum += '0';
        }
        return binNum;
    }
};