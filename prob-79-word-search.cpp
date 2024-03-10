#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {

        // check if all the letters of the word are present in the board atleast
        // once:
        for (auto x : word)
        {
            bool flag{};
            for (int i{}; i < board.size(); ++i)
            {
                for (int j{}; j < board[0].size(); ++j)
                {
                    if (x == board[i][j])
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    break;
            }
            if (!flag)
                return false;
        }

        // create the options storage and state storage:
        int len{static_cast<int>(word.size())};
        vector<vector<vector<int>>> optStorage(len);
        vector<vector<vector<char>>> matStates(len);

        // search all the occurrences of word[0] in board:
        vector<vector<int>> initialOccur;
        int m{static_cast<int>(board.size())};
        int n{static_cast<int>(board[0].size())};
        for (int i{}; i < m; ++i)
        {
            for (int j{}; j < n; ++j)
            {
                if (board[i][j] == word[0])
                    initialOccur.push_back({i, j});
            }
        }

        if (word.size() == 1)
            if (initialOccur.size() == 0)
                return false;
            else
                return true;

        // store these occurrences and the current state of matrix to the
        // storage:
        optStorage[0] = initialOccur;
        matStates[0] = board;

        // loop untill all the letters of the pattern are found:
        int i{};
        while (0 <= i && i < len)
        {
            // pop the top state of optStorage[i]:
            if (optStorage[i].size() == 0)
            {
                matStates[i] = {};
                --i;
                continue;
            }
            vector<int> state;
            state = optStorage[i].back();
            optStorage[i].pop_back();

            // mark the current copy of matrix state as '#':
            vector<vector<char>> copyBoard{matStates[i]};
            copyBoard[state[0]][state[1]] = '#';

            // find all the occurrences of word[i+1] in the copyBoard adjacent
            // to copyBoard[state[0]][state[1]]:
            vector<vector<int>> occurrences;
            if (state[0] - 1 >= 0)
            {
                if (copyBoard[state[0] - 1][state[1]] == word[i + 1])
                    occurrences.push_back({state[0] - 1, state[1]});
            }
            if (state[0] + 1 < m)
            {
                if (copyBoard[state[0] + 1][state[1]] == word[i + 1])
                    occurrences.push_back({state[0] + 1, state[1]});
            }
            if (state[1] - 1 >= 0)
            {
                if (copyBoard[state[0]][state[1] - 1] == word[i + 1])
                    occurrences.push_back({state[0], state[1] - 1});
            }
            if (state[1] + 1 < n)
            {
                if (copyBoard[state[0]][state[1] + 1] == word[i + 1])
                    occurrences.push_back({state[0], state[1] + 1});
            }

            if (occurrences.size() == 0)
            {
                continue;
            }
            else if ((i + 1) == (len - 1))
                return true;

            // store these options to optStorage[i+1] and the current copyBoard
            // to matStates[i+1] :
            optStorage[i + 1] = occurrences;
            matStates[i + 1] = copyBoard;

            // increment i
            ++i;
        }
        return false;
    }
};