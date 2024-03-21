#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int finalValueAfterOperations(vector<string> &operations)
    {
        int x{};
        for (auto op : operations)
        {
            if (op[1] == '+')
                ++x;
            else if (op[1] == '-')
                --x;
        }
        return x;
    }
};