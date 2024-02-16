#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());
        vector<int> uniquesFreq;
        int total{};
        for (int i{}; i < arr.size(); ++i)
        {
            int freq{1};
            while (i + 1 < arr.size() && arr[i] == arr[i + 1])
            {
                ++i;
                ++freq;
            }
            total += freq;
            uniquesFreq.push_back(freq);
        }
        sort(uniquesFreq.begin(), uniquesFreq.end());

        int sum{};
        for (int i{}; i < uniquesFreq.size(); ++i)
        {
            sum += uniquesFreq[i];
            if (sum == k)
            {
                return static_cast<int>(uniquesFreq.size() - (i + 1));
            }
            else if (sum > k)
            {
                return static_cast<int>(uniquesFreq.size() - i);
            }
        }
        return 0;
    }
};