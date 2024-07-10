#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        int operations{};
        for (auto log : logs)
        {
            if (log[0] != '.')
                ++operations;
            else if (log[1] == '.')
            {
                if (operations)
                    --operations;
            }
        }
        return operations;
    }
};