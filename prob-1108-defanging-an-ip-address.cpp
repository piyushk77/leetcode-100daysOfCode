#include <string>
using namespace std;

class Solution
{
public:
    string defangIPaddr(string address)
    {
        string defang{"[.]"};
        string defAddr{};
        for (int i{}; i < address.size(); ++i)
        {
            if (address[i] == '.')
                defAddr += defang;
            else
                defAddr += address[i];
        }
        return defAddr;
    }
};