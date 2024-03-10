#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> result;
        for (int i{}; i < nums1.size(); ++i)
        {
            if (binary_search(nums2.begin(), nums2.end(), nums1[i]))
            {
                result.push_back(nums1[i]);
            }
            while ((i + 1) < nums1.size() && nums1[i] == nums1[i + 1])
                ++i;
        }
        return result;
    }
};