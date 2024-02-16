#include <string>
using namespace std;

class Solution
{
public:
    bool squareIsWhite(string coordinates)
    {
        if (coordinates[0] % 2 == 0 && coordinates[1] % 2 == 0)
            return false;
        if (coordinates[0] % 2 != 0 && coordinates[1] % 2 != 0)
            return false;
        return true;
    }
};