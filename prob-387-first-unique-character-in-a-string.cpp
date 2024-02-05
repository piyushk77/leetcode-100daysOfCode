#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<char> str;
        for (auto x : s)
        {
            str.push_back(x);
        }
        for (int i{}; i < str.size(); ++i)
        {
            if (str[i] == '$')
                continue;
            int count{1};
            for (int j{i + 1}; j < str.size(); ++j)
            {
                if (str[j] == '$')
                    continue;
                if (str[i] == str[j])
                {
                    ++count;
                    str[j] = '$';
                }
            }
            if (count == 1)
                return i;
        }
        return -1;
    }
};