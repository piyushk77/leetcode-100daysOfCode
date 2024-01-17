#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        vector<int> freqChart;
        for (int i{}; i < arr.size(); ++i)
        {
            int num{arr[i]}, freq{};
            while (i < arr.size() && num == arr[i])
            {
                ++freq;
                ++i;
            }
            freqChart.push_back(freq);
            --i;
        }
        sort(freqChart.begin(), freqChart.end());
        for (int i{}; i < freqChart.size(); ++i)
        {
            if (i + 1 < freqChart.size() && freqChart[i] == freqChart[i + 1])
                return false;
        }
        return true;
    }
};