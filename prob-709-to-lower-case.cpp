#include <string>
using namespace std;

class Solution
{
public:
    string toLowerCase(string s)
    {
        for (int i{}; i < s.size(); ++i)
            s[i] = tolower(s[i]);
        return s;
    }
};