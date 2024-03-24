#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string sortVowels(string s)
    {
        vector<int> vowelList;
        string res(s.length(), ' ');
        for (int i{}; i < s.length(); ++i)
        {
            char ch{static_cast<char>(tolower(s[i]))};
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                vowelList.push_back(static_cast<int>(s[i]));
            }
            else
                res[i] = s[i];
        }
        sort(vowelList.begin(), vowelList.end(), greater<int>());
        for (int i{}; i < res.length(); ++i)
        {
            if (res[i] == ' ')
            {
                res[i] = static_cast<char>(vowelList.back());
                vowelList.pop_back();
            }
        }
        return res;
    }
};