#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int duplicate{}, missing{};
        for (int i{}; i < nums.size() - 1; ++i)
        {
            if (nums[i] == nums[i + 1])
            {
                duplicate = nums[i];
                nums.erase(nums.begin() + i);
                continue;
            }
        }

        nums.push_back(0);

        for (int i{}; i < nums.size(); ++i)
        {
            if (nums[i] != i + 1)
            {
                missing = i + 1;
                break;
            }
        }

        return {duplicate, missing};
    }
};