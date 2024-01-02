#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        for (int i{static_cast<int>(digits.size() - 1)}, carry{1}; i >= 0;
             --i)
        {
            digits[i] += carry;
            carry = digits[i] / 10;
            if (!carry)
                break;
            digits[i] = digits[i] % 10;
        }

        if (digits[0] == 0)
        {
            digits[0] = 0;
            digits.insert(digits.begin() + 0, 1);
        }

        return digits;
    }
};