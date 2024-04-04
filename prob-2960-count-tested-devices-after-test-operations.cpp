#include<vector>
using namespace std;

class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int count{};
        int n{static_cast<int>(batteryPercentages.size())};
        int sub{};
        for (int i{}; i < n; ++i) {
            if ((batteryPercentages[i] - sub) > 0) {
                ++count;
                ++sub;
            }
        }
        return count;
    }
};