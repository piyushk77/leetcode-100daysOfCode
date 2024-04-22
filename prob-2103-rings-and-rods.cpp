#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int countPoints(string rings)
    {
        int strLen{static_cast<int>(rings.size())};
        int n{strLen / 2};
        vector<vector<int>> hashTable(10, vector<int>(3));
        for (int i{1}; i < strLen; i += 2)
        {
            string rodNum{rings[i]};
            int rod{stoi(rodNum)};
            char color{rings[i - 1]};
            if (color == 'R')
                ++hashTable[rod][0];
            else if (color == 'G')
                ++hashTable[rod][1];
            else if (color == 'B')
                ++hashTable[rod][2];
        }

        int count{};
        for (auto x : hashTable)
        {
            if (x[0] && x[1] && x[2])
                ++count;
        }
        return count;
    }
};