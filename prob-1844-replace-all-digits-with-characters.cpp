#include <string>
using namespace std;

class Solution
{
public:
    string replaceDigits(string s)
    {
        for (int i{1}; i < s.size(); i += 2)
        {
            string temp{s[i]};
            s[i] = s[i - 1] + stoi(temp);
        }
        return s;
    }
};