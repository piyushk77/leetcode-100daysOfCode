#include <vector>
using namespace std;

class Solution
{
public:
    int reverse(int num)
    {
        int rev{};
        while (num)
        {
            int digit{num % 10};
            rev = rev * 10 + digit;
            num /= 10;
        }
        return rev;
    }

    int countDistinctIntegers(vector<int> &nums)
    {
        int len{static_cast<int>(nums.size())};
        for (int i{}; i < len; ++i)
            nums.push_back(reverse(nums[i]));

        int max{};
        for (auto x : nums)
            if (max < x)
                max = x;

        vector<int> hashMap(max);
        for (auto x : nums)
        {
            ++hashMap[x - 1];
        }

        int count{};
        for (auto x : hashMap)
        {
            if (x != 0)
                ++count;
        }
        return count;
    }
};