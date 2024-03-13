#include <vector>
using namespace std;

class Solution
{
public:
    int minMaxDifference(int num)
    {
        vector<int> digits;
        vector<int> temp;
        int revNum{};
        while (num)
        {
            int digit{num % 10};
            temp.push_back(digit);
            num /= 10;
        }
        for (int i{static_cast<int>(temp.size()) - 1}; i >= 0; --i)
        {
            digits.push_back(temp[i]);
        }

        int targetDigit{-1};
        for (int i{}; i < digits.size(); ++i)
        {
            if (digits[i] != 9)
            {
                targetDigit = digits[i];
                break;
            }
        }

        int maxNum{};
        for (auto x : digits)
        {
            if (x == targetDigit)
                x = 9;
            maxNum = maxNum * 10 + x;
        }

        targetDigit = digits[0];
        int minNum{};
        for (auto x : digits)
        {
            if (x == targetDigit)
                x = 0;
            minNum = minNum * 10 + x;
        }

        return maxNum - minNum;
    }
};