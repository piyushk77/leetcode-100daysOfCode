#include <string>
using namespace std;

class Solution
{
public:
    int minimumPushes(string word)
    {
        int press{1}, count{};
        for (int i{1}; i <= word.size(); ++i)
        {
            count += press;
            if (i % 8 == 0)
                ++press;
        }
        return count;
    }
};