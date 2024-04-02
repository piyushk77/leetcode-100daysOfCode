#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int n{static_cast<int>(s.size())};
        const int asciiSize{256};
        vector<int> hashIso(static_cast<int>(asciiSize + 1), -1);
        for (int i{}; i < n; ++i)
        {
            int a{static_cast<int>(s[i])};
            int b{static_cast<int>(t[i])};
            if (hashIso[a] == -1)
            {
                hashIso[a] = b;
            }
            else
            {
                if (hashIso[a] != b)
                    return false;
            }
        }

        vector<int> isoHash(static_cast<int>(asciiSize + 1), -1);
        for (int i{}; i < n; ++i)
        {
            int a{static_cast<int>(s[i])};
            int b{static_cast<int>(t[i])};
            if (isoHash[b] == -1)
            {
                isoHash[b] = a;
            }
            else
            {
                if (isoHash[b] != a)
                    return false;
            }
        }

        return true;
    }
};