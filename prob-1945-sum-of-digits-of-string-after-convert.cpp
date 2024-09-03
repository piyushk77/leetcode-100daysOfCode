#include <string>
using namespace std;

class Solution
{
public:
    int transform(int num)
    {
        int sum{};
        while (num)
        {
            int digit{num % 10};
            sum += digit;
            num /= 10;
        }
        return sum;
    }
    int getVal(char x)
    {
        switch (x)
        {
        case 'a':
            return 1;
        case 'b':
            return 2;
        case 'c':
            return 3;
        case 'd':
            return 4;
        case 'e':
            return 5;
        case 'f':
            return 6;
        case 'g':
            return 7;
        case 'h':
            return 8;
        case 'i':
            return 9;
        case 'j':
            return 1;
        case 'k':
            return 2;
        case 'l':
            return 3;
        case 'm':
            return 4;
        case 'n':
            return 5;
        case 'o':
            return 6;
        case 'p':
            return 7;
        case 'q':
            return 8;
        case 'r':
            return 9;
        case 's':
            return 10;
        case 't':
            return 2;
        case 'u':
            return 3;
        case 'v':
            return 4;
        case 'w':
            return 5;
        case 'x':
            return 6;
        case 'y':
            return 7;
        case 'z':
            return 8;
        default:
            return -1;
        }
    }
    int getInit(string s)
    {
        int sum{};
        for (auto x : s)
        {
            sum += getVal(x);
        }
        return sum;
    }
    int getLucky(string s, int k)
    {
        --k;
        int val{getInit(s)};
        for (int i{1}; i <= k; ++i)
            val = transform(val);
        return val;
    }
};