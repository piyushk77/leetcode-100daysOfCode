#include <vector>
using namespace std;

class Solution
{
public:
    int genSeqNum(int start, int digits)
    {
        int num{};
        for (int i{1}; i <= digits; ++i)
        {
            num = (num * 10) + (start++);
        }
        return num;
    }

    vector<int> sequentialDigits(int low, int high)
    {
        int lowTemp{low}, highTemp{high};

        int lowDigits{};
        while (lowTemp)
        {
            lowTemp /= 10;
            ++lowDigits;
        }

        int highDigits{};
        while (highTemp)
        {
            highTemp /= 10;
            ++highDigits;
        }

        vector<int> result;
        for (int digits{lowDigits}; digits <= highDigits; ++digits)
        {
            for (int i{1}; i <= 10 - digits; ++i)
            {
                int seqNum{genSeqNum(i, digits)};
                if (seqNum >= low && seqNum <= high)
                    result.push_back(seqNum);
            }
        }

        return result;
    }
};