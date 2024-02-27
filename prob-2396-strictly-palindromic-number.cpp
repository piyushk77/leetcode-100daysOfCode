#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> changeBaseTo(int num, int base)
    {
        vector<int> res;
        while (num >= base)
        {
            int rem{num % base};
            res.push_back(rem);
            num /= base;
        }
        res.push_back(num);
        return res;
    }

    bool isPalindromeVector(vector<int> n)
    {
        vector<int> revN;
        for (int i{static_cast<int>(n.size()) - 1}; i >= 0; --i)
        {
            revN.push_back(n[i]);
        }
        for (int i{}; i < n.size(); ++i)
        {
            if (n[i] != revN[i])
                return false;
        }
        return true;
    }

    bool isStrictlyPalindromic(int n)
    {
        for (int i{2}; i <= n - 2; ++i)
        {
            if (!isPalindromeVector(changeBaseTo(n, i)))
                return false;
        }
        return true;
    }
};