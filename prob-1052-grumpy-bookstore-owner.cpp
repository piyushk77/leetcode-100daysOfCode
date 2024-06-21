#include <vector>
using namespace std;

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int n{static_cast<int>(customers.size())};
        int windowSum{};
        int maxSum{};
        int zeroSum{};
        int i{};
        while (i < n)
        {

            // Iterate and add customers to currentSum untill encounter 1 in grumpy
            while (i < n && grumpy[i] != 1)
            {
                zeroSum += customers[i];
                ++i;
            }

            // Iterate and add customers for the next *minutes* min
            int start{i};
            for (int min{1}; i < n && min <= minutes; ++min)
            {
                windowSum += customers[i++];
            }

            while (i < n && grumpy[i] != 1)
            {
                windowSum += customers[i++];
            }

            // Calculate post zero sum
            int postZeroSum{};
            for (int x{i}; x < n; ++x)
                if (grumpy[x] != 1)
                    postZeroSum += customers[x];

            // Compare with the maxSum
            if (maxSum < windowSum + zeroSum + postZeroSum)
            {
                maxSum = windowSum + zeroSum + postZeroSum;
            }

            windowSum = 0;
            i = start + 1;
        }

        return maxSum;
    }
};