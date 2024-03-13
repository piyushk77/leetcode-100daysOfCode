#include <vector>
#include <stdlib.h>
using namespace std;

class Solution
{
    vector<int> numList;

public:
    Solution(vector<int> &nums) { numList = nums; }

    int pick(int target)
    {
        vector<int> targetIndices;
        for (int i{}; i < numList.size(); ++i)
        {
            if (numList[i] == target)
                targetIndices.push_back(i);
        }
        return targetIndices[rand() % targetIndices.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */