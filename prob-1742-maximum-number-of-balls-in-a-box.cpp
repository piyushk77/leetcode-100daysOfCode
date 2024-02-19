#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int digitSum(int n)
    {
        int sum{};
        while (n)
        {
            int digit{n % 10};
            sum += digit;
            n /= 10;
        }
        return sum;
    }
    int countBalls(int lowLimit, int highLimit)
    {
        vector<int> collection;
        for (int i{lowLimit}; i <= highLimit; ++i)
        {
            collection.push_back(digitSum(i));
        }
        sort(collection.begin(), collection.end());
        int max{};
        for (int i{}; i < collection.size(); ++i)
        {
            int freq{1};
            while (i + 1 < collection.size() &&
                   collection[i] == collection[i + 1])
            {
                ++freq;
                ++i;
            }
            if (max < freq)
                max = freq;
        }
        return max;
    }
};