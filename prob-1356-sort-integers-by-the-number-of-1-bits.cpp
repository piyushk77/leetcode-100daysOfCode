#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    static bool comp(int a, int b)
    {
        int oneA{}, oneB{};
        int mask{1};
        const int SIZE{static_cast<int>(sizeof(int))};
        for (int i{}; i < SIZE * 8; ++i)
        {
            if (a & (mask << i))
                ++oneA;
            if (b & (mask << i))
                ++oneB;
        }

        if (oneA < oneB)
            return true;
        else if (oneB < oneA)
            return false;
        else
        {
            if (a < b)
                return true;
            else
                return false;
        }
    }

    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};