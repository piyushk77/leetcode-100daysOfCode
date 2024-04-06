#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> separateDigits(vector<int> &nums)
    {
        vector<int> digits;
        for (auto num : nums)
        {
            vector<int> numdigits;
            while (num)
            {
                numdigits.push_back(num % 10);
                num /= 10;
            }
            for (int i{static_cast<int>(numdigits.size()) - 1}; i >= 0; --i)
            {
                digits.push_back(numdigits[i]);
            }
        }
        return digits;
    }
};