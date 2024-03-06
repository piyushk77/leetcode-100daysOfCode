#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> memLeak(int memory1, int memory2)
    {
        int i{};
        while (true)
        {
            ++i;
            if (memory1 < memory2)
            {
                if (memory2 - i < 0)
                    break;
                memory2 -= i;
            }
            else
            {
                if (memory1 - i < 0)
                    break;
                memory1 -= i;
            }
        }
        return {i, memory1, memory2};
    }
};