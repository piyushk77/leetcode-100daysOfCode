#include <vector>
using namespace std;

class Solution
{
public:
    int wateringPlants(vector<int> &plants, int capacity)
    {
        int steps{static_cast<int>(plants.size())};
        int sum{};
        for (int i{}; i < plants.size(); ++i)
        {
            sum += plants[i];
            if (capacity < sum)
            {
                steps += (2 * i);
                sum = plants[i];
            }
        }
        return steps;
    }
};