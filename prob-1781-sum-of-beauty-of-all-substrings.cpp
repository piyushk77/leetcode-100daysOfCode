#include <vector>
#include <string>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int beautySum(string s)
    {
        int lenS{static_cast<int>(s.size())};
        int sum{};
        for (int win{1}; win <= s.size(); ++win)
        {
            for (int i{}; i < lenS - win + 1; ++i)
            {
                int max{}, min{INT_MAX};
                vector<int> hashTable(static_cast<int>('z') + 1);
                for (int j{i}; j < i + win; ++j)
                {
                    ++hashTable[static_cast<int>(s[j])];
                }
                for (auto x : hashTable)
                {
                    if (max < x)
                        max = x;
                    if (min > x && x)
                        min = x;
                }
                sum += (max - min);
            }
        }
        return sum;
    }
};