#include <vector>
using namespace std;

class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        int max{};
        for (auto x : costs)
            if (max < x)
                max = x;

        vector<int> countArray(max + 1, 0);

        for (auto x : costs)
            ++countArray[x];

        int prefixSum{};

        for (int i{}; i < countArray.size(); ++i)
        {
            prefixSum += countArray[i];
            countArray[i] = prefixSum;
        }

        vector<int> outputArray(static_cast<int>(costs.size()));
        for (int i{static_cast<int>(costs.size()) - 1}; i >= 0; --i)
        {
            outputArray[countArray[costs[i]] - 1] = costs[i];
            countArray[costs[i]]--;
        }

        int count{};
        for (int i{}; i < outputArray.size(); ++i)
        {
            coins -= outputArray[i];
            if (coins >= 0)
                ++count;
            else
                break;
        }

        return count;
    }
};