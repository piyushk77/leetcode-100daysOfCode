#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<bool> camelMatch(vector<string> &queries, string pattern)
    {
        vector<bool> answer;
        for (auto query : queries)
        {
            int i{};
            bool flag{true};
            for (int j{}; j < pattern.size(); ++j)
            {
                while (i < query.size() && query[i] != pattern[j])
                {
                    if (isupper(query[i]))
                    {
                        flag = false;
                        answer.push_back(false);
                        break;
                    }
                    ++i;
                }
                if (!flag)
                    break;
                if (i < query.size() && query[i] == pattern[j])
                {
                    ++i;
                    continue;
                }
                else
                {
                    flag = false;
                    answer.push_back(false);
                    break;
                }
            }
            if (flag)
            {
                ++i;
                for (; i < query.size(); ++i)
                    if (isupper(query[i]))
                    {
                        flag = false;
                        answer.push_back(false);
                        break;
                    }
                if (flag)
                    answer.push_back(true);
            }
        }
        return answer;
    }
};