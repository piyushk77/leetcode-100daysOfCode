#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    static bool comp(vector<int> a, vector<int> b) { return a[1] > b[1]; }
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(), comp);
        int units{};
        for (auto box : boxTypes)
        {
            if (truckSize <= 0)
                break;
            if (box[0] <= truckSize)
            {
                units += box[1] * box[0];
                truckSize -= box[0];
            }
            else
            {
                units += box[1] * truckSize;
                truckSize -= box[0];
            }
        }
        return units;
    }
};