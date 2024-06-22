#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n{static_cast<int>(nums.size())};

        queue<int> odds;
        for (int m{}; m < n; ++m)
            if (nums[m] % 2)
                odds.push(m);

        int i{}, j{};
        int start{-1}, end{-1};
        int subArrays{};
        int count{};

        while (j < n)
        {

            while (j < n && !(nums[j] % 2))
                ++j;

            if (j < n)
                start = odds.front();

            while (j < n && count != k)
            {
                if (nums[j] % 2)
                    ++count;
                ++j;
            }

            if (count == k)
                end = j - 1;

            while (j < n && !(nums[j] % 2))
                ++j;

            if (start != -1 && end != -1)
                subArrays += (start - i + 1) * (j - end);

            i = start + 1;
            --count;
            start = end = -1;
            odds.pop();
        }

        return subArrays;
    }
};