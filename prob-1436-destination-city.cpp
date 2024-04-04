#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        for (auto x : paths)
        {
            bool found{false};
            for (auto y : paths)
            {
                if (x[1] == y[0])
                {
                    found = true;
                    break;
                }
            }
            if (!found)
                return x[1];
        }
        return "";
    }
};