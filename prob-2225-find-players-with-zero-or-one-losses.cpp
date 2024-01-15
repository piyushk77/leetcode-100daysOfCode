#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {

        // generate the list of all the players who atleast lost or won a match
        vector<int> lost, won;
        for (auto match : matches)
        {
            won.push_back(match[0]);
            lost.push_back(match[1]);
        }

        // sort the lists of players
        sort(won.begin(), won.end());
        sort(lost.begin(), lost.end());

        // delete multiple occurrences of players who won atleast one match
        vector<int> winners;
        for (int i{}; i < won.size(); ++i)
        {
            while (i + 1 < won.size() && won[i] == won[i + 1])
            {
                ++i;
            }
            winners.push_back(won[i]);
        }

        vector<int> loosers;
        for (int i{}; i < lost.size(); ++i)
        {
            while (i + 1 < lost.size() && lost[i] == lost[i + 1])
            {
                ++i;
            }
            loosers.push_back(lost[i]);
        }

        for (int i{}; i < loosers.size(); ++i)
        {
            int index{static_cast<int>(
                lower_bound(winners.begin(), winners.end(), loosers[i]) -
                winners.begin())};
            if (index < winners.size() && winners[index] == loosers[i])
                winners[index] = -1;
        }

        vector<int> winOne;
        for (auto x : winners)
        {
            if (x != -1)
                winOne.push_back(x);
        }

        vector<int> lostOne;
        for (int i{}; i < lost.size(); ++i)
        {
            int temp{lost[i]};
            bool flag{};
            ++i;
            while (i < lost.size() && temp == lost[i])
            {
                ++i;
                flag = true;
            }
            --i;
            if (!flag)
            {
                lostOne.push_back(lost[i]);
            }
        }

        vector<vector<int>> res{winOne, lostOne};

        return res;
    }
};