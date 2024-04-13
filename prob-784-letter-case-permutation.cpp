#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution
{
public:
    void caseIncr(string &s)
    {
        int len{static_cast<int>(s.size())};
        int i{len - 1};
        while (i >= 0 && isdigit(s[i]))
            --i;
        if (i >= 0 && islower(s[i]))
        {
            s[i] = toupper(s[i]);
            return;
        }
        else
        {
            while (i >= 0 && isupper(s[i]))
            {
                s[i] = tolower(s[i]);
                --i;
                while (i >= 0 && isdigit(s[i]))
                    --i;
            }
            if (i >= 0)
                s[i] = toupper(s[i]);
        }
    }
    vector<string> letterCasePermutation(string s)
    {
        int letters{};
        for (int i{}; i < s.size(); ++i)
        {
            if (isalpha(s[i]))
            {
                ++letters;
                s[i] = tolower(s[i]);
            }
        }

        vector<string> answer;
        for (int i{}; i < pow(2, letters); ++i)
        {
            caseIncr(s);
            answer.push_back(s);
        }

        return answer;
    }
};