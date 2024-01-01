#include <vector>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int upperLimit{2147483647};
        int lowerLimit{-2147483648};

        int rev{};
        bool willExceedLimit{};

        // store each digit as a vector element

        vector<short> upperDigits;
        int temp{upperLimit};
        while (temp)
        {
            int unitDigit = temp % 10;
            upperDigits.push_back(unitDigit);
            temp /= 10;
        }

        vector<short> lowerDigits;
        temp = lowerLimit;
        while (temp)
        {
            int unitDigit = -(temp % 10);
            lowerDigits.push_back(unitDigit);
            temp /= 10;
        }

        // count number of digits in x

        temp = x;
        int xdigits{};
        while (temp)
        {
            ++xdigits;
            temp /= 10;
        }

        if (xdigits == upperDigits.size())
        {
            if (x <= 0)
            {
                temp = x;
                for (int i{static_cast<int>(lowerDigits.size() - 1)}; i >= 0;
                     --i)
                {
                    int unitDigit = -(temp % 10);
                    temp /= 10;
                    if (unitDigit > lowerDigits[i])
                    {
                        willExceedLimit = true;
                        break;
                    }
                    else if (unitDigit < lowerDigits[i])
                    {
                        break;
                    }
                }
            }
            else
            {
                temp = x;
                for (int i{static_cast<int>(upperDigits.size() - 1)}; i >= 0;
                     --i)
                {
                    int unitDigit = (temp % 10);
                    temp /= 10;
                    if (unitDigit > upperDigits[i])
                    {
                        willExceedLimit = true;
                        break;
                    }
                    else if (unitDigit < upperDigits[i])
                    {
                        break;
                    }
                }
            }
        }

        if (willExceedLimit)
            return 0;

        temp = x;
        if (x <= 0)
        {
            while (temp)
            {
                int unitDigit = -(temp % 10);
                rev = rev * 10 + unitDigit;
                temp /= 10;
            }
            rev *= -1;
        }
        else
        {
            while (temp)
            {
                int unitDigit = (temp % 10);
                rev = rev * 10 + unitDigit;
                temp /= 10;
            }
        }

        return rev;
    }
};