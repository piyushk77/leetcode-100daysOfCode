#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        string res{s};
        for (int i{}; i < s.length(); ++i)
        {
            res[indices[i]] = s[i];
        }
        return res;
    }
};