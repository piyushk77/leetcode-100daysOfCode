#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        int n{static_cast<int>(num.size())};
        vector<int> vecK;
        while (k)
        {
            int digit{k % 10};
            vecK.push_back(digit);
            k /= 10;
        }
        if (num.size() < vecK.size())
        {
            vector<int> temp(static_cast<int>(vecK.size()));
            for (int i{n - 1}, j{static_cast<int>(temp.size()) - 1}; i >= 0;
                 --i, --j)
                temp[j] = num[i];
            n = static_cast<int>(temp.size());
            num = temp;
        }
        vector<int> num2(n - static_cast<int>(vecK.size()));
        for (int i{static_cast<int>(vecK.size()) - 1}; i >= 0; --i)
        {
            num2.push_back(vecK[i]);
        }
        int carry{};
        vector<int> res(n);
        for (int i{n - 1}; i >= 0; --i)
        {
            int sum = num[i] + num2[i] + carry;
            if (sum > 9)
            {
                carry = 1;
                sum -= 10;
            }
            else
            {
                carry = 0;
            }
            res[i] = sum;
        }

        if (carry)
        {
            vector<int> bigRes;
            bigRes.push_back(carry);
            for (auto x : res)
                bigRes.push_back(x);
            return bigRes;
        }
        return res;
    }
};