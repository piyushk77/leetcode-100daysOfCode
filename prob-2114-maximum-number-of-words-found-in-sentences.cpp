#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int mostWordsFound(vector<string> &sentences)
    {
        int max{};
        for (auto s : sentences)
        {
            int count{};
            for (auto x : s)
            {
                if (x == ' ')
                    ++count;
            }
            if (max < (count + 1))
                max = count + 1;
        }
        return max;
    }
};