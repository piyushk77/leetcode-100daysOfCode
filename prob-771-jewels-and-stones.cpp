#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        vector<bool> stoneHash(static_cast<int>('z') + 1, false);
        for (auto x : jewels)
            stoneHash[static_cast<int>(x)] = true;
        int count{};
        for (auto x : stones)
            if (stoneHash[static_cast<int>(x)])
                ++count;
        return count;
    }
};