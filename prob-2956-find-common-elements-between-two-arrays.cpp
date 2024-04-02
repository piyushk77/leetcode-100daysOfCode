#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findIntersectionValues(vector<int> &nums1, vector<int> &nums2)
    {
        const int constraint{100};
        vector<int> hashOne(constraint + 1);
        vector<int> hashTwo(constraint + 2);
        for (auto x : nums1)
            hashOne[x] = 1;
        for (auto y : nums2)
            hashTwo[y] = 1;

        vector<int> answer;
        int count{};
        for (auto x : nums1)
            if (hashTwo[x])
                ++count;
        answer.push_back(count);
        count = 0;
        for (auto x : nums2)
            if (hashOne[x])
                ++count;
        answer.push_back(count);
        return answer;
    }
};