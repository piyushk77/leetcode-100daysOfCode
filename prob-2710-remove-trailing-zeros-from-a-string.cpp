#include <string>
using namespace std;

class Solution
{
public:
    string removeTrailingZeros(string num)
    {
        int count{static_cast<int>(num.size())};
        while (num[count - 1] == '0')
            --count;
        return num.substr(0, count);
    }
};