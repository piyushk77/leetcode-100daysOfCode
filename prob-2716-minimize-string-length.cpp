#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int minimizedStringLength(string s)
    {
        unordered_map<char, int> m;
        for (auto x : s)
            m[x]++;
        return m.size();
    }
};