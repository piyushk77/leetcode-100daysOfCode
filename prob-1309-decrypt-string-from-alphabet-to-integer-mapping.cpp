#include <string>
using namespace std;

class Solution
{
public:
    char getChar(int n)
    {
        char start{static_cast<int>('a') - 1};
        return (start + n);
    }
    string freqAlphabets(string s)
    {
        string decrypt{};
        int len{static_cast<int>(s.size())};
        for (int i{}; i < len; ++i)
        {
            if (((i + 2) < len) && s[i + 2] == '#')
            {
                decrypt += getChar(stoi(s.substr(i, 2)));
                i += 2;
            }
            else
            {
                string ch{s[i]};
                decrypt += getChar(stoi(ch));
            }
        }
        return decrypt;
    }
};