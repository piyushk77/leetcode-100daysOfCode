#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int numOfStrings(vector<string> &patterns, string word)
    {
        int wordLen{static_cast<int>(word.size())};
        int count{};
        for (auto x : patterns)
        {
            int patLen{static_cast<int>(x.size())};
            for (int i{}; i <= wordLen - patLen; ++i)
            {
                if (word[i] == x[0])
                {
                    string subStr{word.substr(i, patLen)};
                    if (subStr == x)
                    {
                        ++count;
                        break;
                    }
                }
            }
        }
        return count;
    }
};