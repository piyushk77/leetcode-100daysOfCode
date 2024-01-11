#include <vector>
using namespace std;

class Solution
{
public:
    int gcd(int x, int y)
    {
        int large{max(x, y)};
        int small{min(x, y)};
        if (large % small == 0)
            return small;

        return gcd(large % small, small);
    }
    int countBeautifulPairs(vector<int> &nums)
    {
        vector<int> firstDigits, lastDigits;

        for (auto x : nums)
        {
            int digit;
            while (x)
            {
                digit = x;
                x /= 10;
            }
            firstDigits.push_back(digit);
        }

        for (auto x : nums)
        {
            int digit{x % 10};
            lastDigits.push_back(digit);
        }

        int pair{};

        for (int i{}; i < nums.size() - 1; ++i)
        {
            for (int j{i + 1}; j < nums.size(); ++j)
            {
                if (gcd(firstDigits[i], lastDigits[j]) == 1)
                {
                    ++pair;
                }
            }
        }

        return pair;
    }
};