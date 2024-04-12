#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string smallestNumber(string pattern)
    {
        int len{static_cast<int>(pattern.size())};
        vector<int> answer;
        vector<int> markings(10);
        markings[0] = -1;
        int min{1};

        for (int i{}; i < pattern.size(); ++i)
        {
            if (pattern[i] == 'I')
            {
                markings[min] = -1;
                answer.push_back(min);
                while (min < markings.size() && markings[min] == -1)
                    ++min;
            }
            else
            {
                int count{};
                while (i < pattern.size() && pattern[i] == 'D')
                {
                    ++count;
                    ++i;
                }
                --i;
                while (count)
                {
                    answer.push_back(min + count);
                    markings[min + count] = -1;
                    --count;
                }
            }
        }

        string ans{};
        answer.push_back(min);
        for (auto x : answer)
            ans += to_string(x);
        return ans;
    }
};