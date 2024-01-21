#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool formsTriangle(int first, int second, int third)
    {
        if (first < second + third)
            if (second < first + third)
                if (third < first + second)
                    return true;
        return false;
    }

    int largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        for (int i{}; i <= nums.size() - 3; ++i)
        {
            int firstSide{nums[i]};
            int secondSide{nums[i + 1]};
            int thirdSide{nums[i + 2]};

            if (formsTriangle(firstSide, secondSide, thirdSide))
                return firstSide + secondSide + thirdSide;
        }
        return 0;
    }
};