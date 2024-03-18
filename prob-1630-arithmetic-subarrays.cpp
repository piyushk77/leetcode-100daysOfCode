#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isAp(vector<int> arr)
    {
        if (arr.size() < 2)
            return false;
        int d{arr[1] - arr[0]};
        for (int i{1}; i < arr.size(); ++i)
        {
            if ((arr[i] - arr[i - 1]) != d)
                return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l,
                                          vector<int> &r)
    {
        int m{static_cast<int>(l.size())};
        vector<bool> answer;
        for (int i{}; i < m; ++i)
        {
            auto start = nums.begin() + l[i];
            auto end = nums.begin() + r[i] + 1;
            vector<int> slice(r[i] - l[i] + 1);
            copy(start, end, slice.begin());
            sort(slice.begin(), slice.end());
            answer.push_back(isAp(slice));
        }
        return answer;
    }
};