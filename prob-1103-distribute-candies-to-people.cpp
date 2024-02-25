#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        int dist{static_cast<int>(
            (sqrt(1 + 8 * static_cast<long>(candies)) - 1) / 2)};
        int m{dist / num_people};
        vector<int> res;
        for (int i{}; i < num_people; ++i)
        {
            int total{(i + 1) * m + num_people * ((m * (m - 1)) / 2)};
            res.push_back(total);
            candies -= total;
        }
        int nextCandy{num_people * m + 1};
        int i{};
        while (candies > 0)
        {
            candies -= nextCandy;
            if (candies >= 0)
                res[i] += nextCandy;
            else
                res[i] += candies + nextCandy;
            ++i;
            ++nextCandy;
        }
        return res;
    }
};