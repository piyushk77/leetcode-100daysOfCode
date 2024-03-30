#include <vector>
using namespace std;

class Solution
{
public:
    bool checkDirectAttack(vector<vector<int>> &board, vector<int> &queen)
    {
        int sum{};
        int x{queen[0]};
        int y{queen[1]};
        // check left H attack
        for (int j{y}; j >= 0; --j)
        {
            sum += board[x][j];
            if (board[x][j] == -1)
                break;
        }
        if (!sum)
            return true;

        // check right H attack
        sum = 0;
        for (int j{y}; j < board[0].size(); ++j)
        {
            sum += board[x][j];
            if (board[x][j] == -1)
                break;
        }
        if (!sum)
            return true;

        // check top V attack
        sum = 0;
        for (int i{x}; i >= 0; --i)
        {
            sum += board[i][y];
            if (board[i][y] == -1)
                break;
        }
        if (!sum)
            return true;

        // check bottom V attack
        sum = 0;
        for (int i{x}; i < board.size(); ++i)
        {
            sum += board[i][y];
            if (board[i][y] == -1)
                break;
        }
        if (!sum)
            return true;

        // check  top-left diagonal attack
        sum = 0;
        for (int i{x}, j{y}; i >= 0 && j >= 0; --i, --j)
        {
            sum += board[i][j];
            if (board[i][j] == -1)
                break;
        }
        if (!sum)
            return true;

        // check top-right diagonal attack
        sum = 0;
        for (int i{x}, j{y}; i >= 0 && j < board[0].size(); --i, ++j)
        {
            sum += board[i][j];
            if (board[i][j] == -1)
                break;
        }
        if (!sum)
            return true;

        // check  bottom-right diagonal attack
        sum = 0;
        for (int i{x}, j{y}; i < board.size() && j < board[0].size();
             ++i, ++j)
        {
            sum += board[i][j];
            if (board[i][j] == -1)
                break;
        }
        if (!sum)
            return true;

        // check bottom-left diagonal attack
        sum = 0;
        for (int i{x}, j{y}; j >= 0 && i < board.size(); ++i, --j)
        {
            sum += board[i][j];
            if (board[i][j] == -1)
                break;
        }
        if (!sum)
            return true;

        return false;
    }
    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens,
                                            vector<int> &king)
    {
        vector<vector<int>> board(8, vector<int>(8, 0));
        for (auto x : queens)
        {
            board[x[0]][x[1]] = 1;
        }
        board[king[0]][king[1]] = -1;

        vector<vector<int>> answer;
        for (auto x : queens)
        {
            if (checkDirectAttack(board, x))
                answer.push_back(x);
        }

        return answer;
    }
};