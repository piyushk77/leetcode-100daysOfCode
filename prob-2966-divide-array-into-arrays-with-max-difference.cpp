#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        vector<int> newNums{nums};
        sort(newNums.begin(), newNums.end());
        vector<vector<int>> result;
        for (int i{}; i < newNums.size(); ++i)
        {
            vector<int> newArray;
            int currentNum{newNums[i]};
            newArray.push_back(newNums[i]);
            newNums.erase(newNums.begin() + i);
            --i;
            int count{1};
            for (int j{i + 1}; j < newNums.size(); ++j)
            {
                if (count == 3)
                    break;
                if (abs(newNums[j] - currentNum) <= k)
                {
                    newArray.push_back(newNums[j]);
                    newNums.erase(newNums.begin() + j);
                    --j;
                    ++count;
                }
            }
            if (count != 3)
                return {};
            result.push_back(newArray);
        }
        return result;
    }
};