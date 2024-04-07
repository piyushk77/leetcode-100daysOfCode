#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> diStringMatch(string s)
    {
        int n{static_cast<int>(s.size())};
        int low{}, high{n};
        vector<int> perm;
        for (auto x : s)
        {
            if (x == 'I')
                perm.push_back(low++);
            else
                perm.push_back(high--);
        }
        if (s[n - 1] == 'I')
            perm.push_back(high);
        else
            perm.push_back(low);
        return perm;
    }
};