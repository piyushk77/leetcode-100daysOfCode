#include <string>
using namespace std;

class Solution
{
public:
    string categorizeBox(int length, int width, int height, int mass)
    {
        const long long volMax{1'000'000'000}, lenMax{1'00'00};
        long long volume{static_cast<long long>(length) *
                         static_cast<long long>(width) *
                         static_cast<long long>(height)};
        bool bulky{}, heavy{};

        if ((length >= lenMax) || (width >= lenMax) || (height >= lenMax) ||
            (volume >= volMax))
            bulky = true;
        if (mass >= 100)
            heavy = true;

        if (bulky && heavy)
            return "Both";
        if (!bulky && !heavy)
            return "Neither";
        if (bulky && !heavy)
            return "Bulky";
        if (!bulky && heavy)
            return "Heavy";
        else
            return "Error";
    }
};