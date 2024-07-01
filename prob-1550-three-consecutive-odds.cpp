#include <vector>
using namespace std;

class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int n{static_cast<int>(arr.size())};
        for (int i{2}; i < n; ++i)
            if (arr[i - 2] % 2 && arr[i - 1] % 2 && arr[i] % 2)
                return true;
        return false;
    }
};