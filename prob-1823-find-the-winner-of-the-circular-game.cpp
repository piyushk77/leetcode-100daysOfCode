#include <vector>
using namespace std;

class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        vector<int> players;
        for (int i{1}; i <= n; ++i)
            players.push_back(i);
        int mark{1};
        while (n > 1)
        {
            int offset{k % n};
            mark += (offset - 1);
            if (mark > n)
            {
                mark %= n;
            }
            else if (mark <= 0)
            {
                mark = n + mark;
            }
            int index{mark - 1};
            players.erase(players.begin() + index);
            if (mark == n)
                mark = 1;
            --n;
        }
        return players[0];
    }
};