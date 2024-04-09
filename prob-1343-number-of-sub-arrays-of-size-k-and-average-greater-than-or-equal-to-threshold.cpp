#include <vector>
using namespace std;

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        int winSum{};
        for (int i{}; i < k; ++i)
            winSum += arr[i];
        int n{static_cast<int>(arr.size())};
        int count{};
        for (int i{}; i < n - k; ++i)
        {
            int avg{winSum / k};
            if (avg >= threshold)
                ++count;
            winSum -= arr[i];
            winSum += arr[i + k];
        }
        int avg{winSum / k};
        if (avg >= threshold)
            ++count;
        return count;
    }
};