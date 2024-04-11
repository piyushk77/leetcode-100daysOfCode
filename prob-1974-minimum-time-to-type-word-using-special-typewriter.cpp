#include <string>
using namespace std;

class Solution
{
public:
    int minTimeToType(string word)
    {
        int asciiStart{static_cast<int>('a')};
        --asciiStart;
        int alphabets{static_cast<int>('z') - static_cast<int>('a') + 1};
        char current{'a'};
        int time{};
        for (auto letter : word)
        {
            ++time;
            int clockWise{(static_cast<int>(letter) - asciiStart) -
                          (static_cast<int>(current) - asciiStart)};
            if (clockWise < 0)
                clockWise += alphabets;
            int anticlockWise{alphabets - clockWise};
            time += min(clockWise, anticlockWise);
            current = letter;
        }
        return time;
    }
};