#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        vector<int> hashTable(static_cast<int>('z') + 1);
        for (auto x : sentence)
        {
            ++hashTable[x];
        }
        for (int i{static_cast<int>('a')}; i <= static_cast<int>('z'); ++i)
            if (!hashTable[i])
                return false;
        return true;
    }
};