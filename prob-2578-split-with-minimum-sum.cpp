#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int splitNum(int num)
    {
        vector<int> digits;
        while (num)
        {
            int digit{num % 10};
            digits.push_back(digit);
            num /= 10;
        }

        sort(digits.begin(), digits.end());
        int num1{}, num2{};
        for (int i{}; i < digits.size(); ++i)
        {
            if (i % 2)
            {
                num2 = num2 * 10 + digits[i];
            }
            else
            {
                num1 = num1 * 10 + digits[i];
            }
        }

        return num1 + num2;
    }
};