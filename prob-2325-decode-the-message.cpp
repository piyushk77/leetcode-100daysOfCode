#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string decodeMessage(string key, string message)
    {
        char ch{'a'};
        vector<char> hashKey(static_cast<int>('z') + 1);
        for (auto x : key)
            if (x == ' ')
                continue;
            else if (!hashKey[x])
            {
                hashKey[x] = ch;
                ++ch;
            }

        hashKey[static_cast<int>(' ')] = ' ';

        string decode{};
        for (auto x : message)
            decode += hashKey[x];

        return decode;
    }
};