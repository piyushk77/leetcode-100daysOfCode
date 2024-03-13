#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    vector<int> digitFrequency(long long num)
    {
        vector<int> freq(10);
        while (num)
        {
            long long digit{num % 10};
            ++freq[digit];
            num /= 10;
        }
        return freq;
    }
    bool areEqual(vector<int> x, vector<int> y)
    {
        for (int i{}; i < x.size(); ++i)
            if (x[i] != y[i])
                return false;
        return true;
    }
    bool reorderedPowerOf2(int n)
    {
        if (n == 1)
            return true;
        vector<long long> powerList;
        for (int i{1}; i <= 32; ++i)
        {
            powerList.push_back(pow(2, i));
        }
        vector<int> mainFreq{digitFrequency(n)};
        for (auto x : powerList)
        {
            if (areEqual(mainFreq, digitFrequency(x)))
                return true;
        }
        return false;
    }
};