#include <vector>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int len{static_cast<int>(s.size())};
        for (int i{}, j{len - 1}; i < len / 2; ++i, --j)
        {
            char temp{s[i]};
            s[i] = s[j];
            s[j] = temp;
        }
    }
};