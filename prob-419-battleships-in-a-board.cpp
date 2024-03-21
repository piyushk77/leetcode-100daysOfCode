#include <vector>
using namespace std;

class Solution
{
public:
    void sink(int i, int j, vector<vector<char>> &board)
    {
        board[i][j] = '.';
        if (i + 1 < board.size())
        {
            if (j + 1 < board[0].size())
            {
                if (board[i + 1][j] == 'X')
                {
                    while (((i + 1) < board.size()) && board[i + 1][j] == 'X')
                    {
                        board[i + 1][j] = '.';
                        ++i;
                    }
                }
                else if (board[i][j + 1] == 'X')
                {
                    while (((j + 1) < board[0].size()) &&
                           board[i][j + 1] == 'X')
                    {
                        board[i][j + 1] = '.';
                        ++j;
                    }
                }
            }
            else
            {
                if (board[i + 1][j] == 'X')
                {
                    while (((i + 1) < board.size()) && board[i + 1][j] == 'X')
                    {
                        board[i + 1][j] = '.';
                        ++i;
                    }
                }
            }
        }
        else
        {
            if (j + 1 < board[0].size())
            {
                if (board[i][j + 1] == 'X')
                {
                    while (((j + 1) < board[0].size()) &&
                           board[i][j + 1] == 'X')
                    {
                        board[i][j + 1] = '.';
                        ++j;
                    }
                }
            }
        }
    }

    int countBattleships(vector<vector<char>> &board)
    {
        int count{};
        for (int i{}; i < board.size(); ++i)
        {
            for (int j{}; j < board[0].size(); ++j)
            {
                if (board[i][j] == 'X')
                {
                    ++count;
                    sink(i, j, board);
                }
            }
        }
        return count;
    }
};