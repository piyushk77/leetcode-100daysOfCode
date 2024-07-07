#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int countSeniors(vector<string> &details)
    {
        int count{};
        for (auto x : details)
        {
            if (x[11] > '6')
                ++count;
            else if (x[11] == '6')
                if (x[12] > '0')
                    ++count;
        }
        return count;
    }
};