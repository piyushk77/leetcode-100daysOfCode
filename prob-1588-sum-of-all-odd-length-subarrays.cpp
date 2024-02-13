#include <vector>
using namespace std;

class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int netSum{};
        for (int window{1}; window <= arr.size(); window += 2)
        {
            for (int i{}; i < arr.size() - window + 1; ++i)
            {
                for (int j{i}; j < i + window; ++j)
                {
                    netSum += arr[j];
                }
            }
        }
        return netSum;
    }
};