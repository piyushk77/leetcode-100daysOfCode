#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        const int SIZE{2001};
        const int MID{static_cast<int>(SIZE / 2)};
        vector<int> hashNum1(SIZE, 0);
        vector<int> hashNum2(SIZE, 0);
        for (auto x : nums1)
            ++hashNum1[MID + x];
        for (auto x : nums2)
            ++hashNum2[MID + x];

        vector<int> commonNum1;
        vector<int> commonNum2;
        for (int i{}; i < nums1.size(); ++i)
            if (!hashNum2[MID + nums1[i]])
            {
                commonNum1.push_back(nums1[i]);
                ++hashNum2[MID + nums1[i]];
            }

        for (int i{}; i < nums2.size(); ++i)
            if (!hashNum1[MID + nums2[i]])
            {
                commonNum2.push_back(nums2[i]);
                ++hashNum1[MID + nums2[i]];
            }

        return {commonNum1, commonNum2};
    }
};