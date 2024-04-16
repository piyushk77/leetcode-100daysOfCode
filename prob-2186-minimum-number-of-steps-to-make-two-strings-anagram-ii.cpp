#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int minSteps(string s, string t)
    {
        vector<int> hashS(static_cast<int>('z') + 1);
        vector<int> hashT(static_cast<int>('z') + 1);
        for (auto x : s)
        {
            ++hashS[x];
        }
        for (auto x : t)
        {
            ++hashT[x];
        }

        int steps{};
        for (int i{}; i < hashT.size(); ++i)
        {
            if (hashT[i])
            {
                if (hashS[i] < hashT[i])
                    steps += abs(hashS[i] - hashT[i]);
            }
        }

        for (int i{}; i < hashS.size(); ++i)
        {
            if (hashS[i])
            {
                if (hashT[i] < hashS[i])
                    steps += abs(hashS[i] - hashT[i]);
            }
        }
        return steps;
    }
};