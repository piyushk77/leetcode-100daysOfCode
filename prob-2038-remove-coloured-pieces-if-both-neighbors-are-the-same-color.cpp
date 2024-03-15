#include <string>
using namespace std;

class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int countA{}, countB{};
        int n{static_cast<int>(colors.size())};
        for (int i{}; i < n; ++i)
        {
            if (colors[i] == 'A')
            {
                int count{};
                while (i < n && colors[i] == 'A')
                {
                    ++count;
                    ++i;
                }
                --i;
                if (count > 2)
                    countA += (count - 2);
            }
            else
            {
                int count{};
                while (i < n && colors[i] == 'B')
                {
                    ++count;
                    ++i;
                }
                --i;
                if (count > 2)
                    countB += (count - 2);
            }
        }
        if (countA <= countB)
            return false;
        else
            return true;
    }
};