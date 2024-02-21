#include <vector>
using namespace std;

class Solution
{
public:
    inline int sumDigits(int x)
    {
        int sum{};
        while (x)
        {
            int digit{x % 10};
            sum += digit;
            x /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n)
    {
        vector<vector<int>> table;
        for (int i{1}; i <= 36; ++i)
            table.push_back({});
        for (int i{1}; i <= n; ++i)
        {
            int digitSum{sumDigits(i)};
            table[digitSum - 1].push_back(i);
        }

        int max{};
        int res{};
        for (auto x : table)
        {
            if (max < x.size())
                max = x.size();
        }

        for (auto x : table)
        {
            if (x.size() == max)
                ++res;
        }
        return res;
    }
};