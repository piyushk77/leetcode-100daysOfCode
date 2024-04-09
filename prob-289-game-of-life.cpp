#include <vector>
using namespace std;

class Solution
{
public:
    int countNeighbours(vector<vector<int>> &board, int i, int j)
    {
        int count{};
        int m{static_cast<int>(board.size())};
        int n{static_cast<int>(board[0].size())};
        if ((i - 1) >= 0 && (j - 1) >= 0 && board[i - 1][j - 1])
        {
            ++count;
        }
        if ((i - 1) >= 0 && board[i - 1][j])
        {
            ++count;
        }
        if ((i - 1) >= 0 && (j + 1) < n && board[i - 1][j + 1])
        {
            ++count;
        }
        if ((j - 1) >= 0 && board[i][j - 1])
        {
            ++count;
        }
        if ((j + 1) < n && board[i][j + 1])
        {
            ++count;
        }
        if ((i + 1) < m && (j - 1) >= 0 && board[i + 1][j - 1])
        {
            ++count;
        }
        if ((i + 1) < m && board[i + 1][j])
        {
            ++count;
        }
        if ((i + 1) < m && (j + 1) < n && board[i + 1][j + 1])
        {
            ++count;
        }
        return count;
    }
    void gameOfLife(vector<vector<int>> &board)
    {
        vector<vector<int>> boardCopy{board};
        for (int i{}; i < board.size(); ++i)
        {
            for (int j{}; j < board[0].size(); ++j)
            {
                int nbr{countNeighbours(board, i, j)};
                if (nbr < 2)
                    boardCopy[i][j] = 0;
                else if (nbr == 2 || nbr == 3)
                {
                    if (board[i][j])
                        boardCopy[i][j] = 1;
                    else if (nbr == 3)
                        boardCopy[i][j] = 1;
                }
                else if (nbr > 3)
                    boardCopy[i][j] = 0;
            }
        }
        board = boardCopy;
    }
};