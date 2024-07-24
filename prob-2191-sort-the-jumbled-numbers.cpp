#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct comp
{
    vector<int> mapp;
    comp(vector<int> mapp) { this->mapp = mapp; }
    bool operator()(int p, int q)
    {
        // count digits of p and q
        int pDigits{}, qDigits{};
        int pTemp{p}, qTemp{q};
        while (pTemp)
        {
            ++pDigits;
            pTemp /= 10;
        }
        while (qTemp)
        {
            ++qDigits;
            qTemp /= 10;
        }
        // get the map equivalent of p
        int mp{};
        if (!p)
            mp = mapp[p];
        else
        {
            for (int i{pDigits}; i > 0; --i)
            {
                int mtp{static_cast<int>(pow(10, i))};
                int digit{(p % mtp) / (mtp / 10)};
                mp += mapp[digit] * (mtp / 10);
            }
        }
        // get the map equivalent of q
        int mq{};
        if (!q)
            mq = mapp[q];
        else
        {
            for (int i{qDigits}; i > 0; --i)
            {
                int mtp{static_cast<int>(pow(10, i))};
                int digit{(q % mtp) / (mtp / 10)};
                mq += mapp[digit] * (mtp / 10);
            }
        }
        return mp < mq;
    }
};

class Solution
{
public:
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        stable_sort(nums.begin(), nums.end(), comp(mapping));
        return nums;
    }
};