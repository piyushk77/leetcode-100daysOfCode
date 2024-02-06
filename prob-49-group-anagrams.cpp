#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int alphaNum(char a)
    {
        switch (a)
        {
        case 'a':
            return 1;
        case 'b':
            return 2;
        case 'c':
            return 3;
        case 'd':
            return 4;
        case 'e':
            return 5;

        case 'f':
            return 6;
        case 'g':
            return 7;
        case 'h':
            return 8;
        case 'i':
            return 9;
        case 'j':
            return 10;

        case 'k':
            return 11;
        case 'l':
            return 12;
        case 'm':
            return 13;
        case 'n':
            return 14;
        case 'o':
            return 15;

        case 'p':
            return 16;
        case 'q':
            return 17;
        case 'r':
            return 18;
        case 's':
            return 19;
        case 't':
            return 20;

        case 'u':
            return 21;
        case 'v':
            return 22;
        case 'w':
            return 23;
        case 'x':
            return 24;
        case 'y':
            return 25;

        case 'z':
            return 26;

        default:
            return -1;
        }
        return 0;
    }
    bool areAnagrams(string str1, string str2)
    {
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        if (str1 == str2)
            return true;
        return false;
    }
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<int> strHash;
        for (auto x : strs)
        {
            int sum{};
            if (x == "")
            {
                strHash.push_back(0);
                continue;
            }
            for (int i{}; i < x.size(); ++i)
            {
                sum += alphaNum(x[i]);
            }
            strHash.push_back(sum);
        }
        vector<vector<string>> anagrams;
        for (int i{}; i < strHash.size(); ++i)
        {
            vector<string> group;
            group.push_back(strs[i]);
            for (int j{i + 1}; j < strHash.size(); ++j)
            {
                if (strHash[i] == strHash[j])
                {
                    if (!areAnagrams(strs[i], strs[j]))
                        continue;
                    group.push_back(strs[j]);
                    strHash.erase(strHash.begin() + j);
                    strs.erase(strs.begin() + j);
                    --j;
                }
            }
            strHash.erase(strHash.begin() + i);
            strs.erase(strs.begin() + i);
            --i;
            anagrams.push_back(group);
        }
        return anagrams;
    }
};