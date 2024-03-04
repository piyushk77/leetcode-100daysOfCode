#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        sort(tokens.begin(), tokens.end());
        int i{};
        int j{static_cast<int>(tokens.size()) - 1};
        int score{};
        int playedTokens{};
        while (playedTokens <= tokens.size() && i <= j)
        {
            if (score == 0)
            {
                if (power >= tokens[i])
                {
                    ++score;
                    power -= tokens[i];
                    ++i;
                    ++playedTokens;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (power >= tokens[i])
                {
                    ++score;
                    power -= tokens[i];
                    ++i;
                    ++playedTokens;
                }
                else
                {
                    if (i == j)
                        break;
                    power += tokens[j];
                    --j;
                    --score;
                    ++playedTokens;
                }
            }
        }
        return score;
    }
};