#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string first{}, second{};
        for (auto x : word1)
            first += x;
        for (auto x : word2)
            second += x;
        if (first == second)
            return true;
        return false;
    }
};