#include<vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> sortedNums;
        int count{};
        int i{}, j{};
        while (count != m + n)
        {
            if (i >= m)
            {
                while (j < n)
                {
                    sortedNums.push_back(nums2[j]);
                    ++count;
                    ++j;
                }
                break;
            }
            if (j >= n)
            {
                while (i < m)
                {
                    sortedNums.push_back(nums1[i]);
                    ++count;
                    ++i;
                }
                break;
            }
            int header1{nums1[i]};
            int header2{nums2[j]};
            if (header1 <= header2)
            {
                while (i < m && nums1[i] <= header2)
                {
                    sortedNums.push_back(nums1[i]);
                    ++count;
                    ++i;
                }
            }
            else if (header1 > header2)
            {
                while (j < n && nums2[j] < header1)
                {
                    sortedNums.push_back(nums2[j]);
                    ++count;
                    ++j;
                }
            }
        }
        for (int k{}; k < m + n; ++k)
        {
            nums1[k] = sortedNums[k];
        }
    }
};