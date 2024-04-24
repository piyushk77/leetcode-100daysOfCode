#include <string>
using namespace std;

class Solution
{
public:
    int countKeyChanges(string s)
    {
        int count{};
        for (int i{1}; i < s.size(); ++i)
        {
            if (tolower(s[i]) != tolower(s[i - 1]))
                ++count;
        }
        return count;
    }
};