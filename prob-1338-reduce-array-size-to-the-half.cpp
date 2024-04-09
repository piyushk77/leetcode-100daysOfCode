#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        const int SIZE{100000};
        vector<vector<int>> hashArr(SIZE + 1, vector<int>(2, 0));
        for (auto x : arr)
        {
            ++hashArr[x][0];
            hashArr[x][1] = x;
        }
        sort(hashArr.begin(), hashArr.end());
        int i{SIZE};
        int sum{};
        int count{};
        while (sum < static_cast<int>(arr.size()) / 2)
        {
            sum += hashArr[i][0];
            ++count;
            --i;
        }
        return count;
    }
};