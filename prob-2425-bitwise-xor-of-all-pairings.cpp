#include <vector>
using namespace std;

class Solution
{
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        int xor1{}, xor2{};
        for (auto x : nums1)
            xor1 ^= x;
        for (auto y : nums2)
            xor2 ^= y;

        int m{static_cast<int>(nums1.size())};
        int n{static_cast<int>(nums2.size())};

        if (m % 2)
        {
            if (n % 2)
                return xor1 ^ xor2;
            else
                return xor2;
        }
        else
        {
            if (n % 2)
                return xor1;
            else
                return 0;
        }
    }
};