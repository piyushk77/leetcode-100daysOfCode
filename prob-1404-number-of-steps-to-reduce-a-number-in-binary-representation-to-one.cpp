#include <string>
using namespace std;

class Solution
{
public:
    string divideByTwo(string s)
    {
        s.erase(s.begin() + (s.size() - 1));
        return s;
    }
    string addOne(string s, int len)
    {
        if (len == 0)
        {
            return "1";
        }
        if (s[len - 1] == '0')
        {
            s[len - 1] = '1';
            return s;
        }
        else
        {
            return addOne(s.substr(0, len - 1), len - 1) + "0";
        }
    }
    bool isOne(string s)
    {
        if (s.size() == 1 && s[0] == '1')
            return true;
        return false;
    }
    int numSteps(string s)
    {
        int count{};
        while (!isOne(s))
        {
            ++count;
            int len{static_cast<int>(s.size())};
            if (s[len - 1] == '0')
                s = divideByTwo(s);
            else
                s = addOne(s, len);
        }
        return count;
    }
};