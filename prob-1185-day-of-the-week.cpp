#include <string>
using namespace std;

class Solution
{
public:
    string getDay(int x)
    {
        switch (x)
        {
        case 0:
            return "Sunday";
        case 1:
            return "Monday";
        case 2:
            return "Tuesday";
        case 3:
            return "Wednesday";
        case 4:
            return "Thursday";
        case 5:
            return "Friday";
        case 6:
            return "Saturday";
        default:
            return "Error";
        }
    }
    string dayOfTheWeek(int day, int month, int year)
    {
        if (month < 3)
        {
            --year;
        }
        int d{year % 100};
        int c{year / 100};
        int f{};
        month = (month + 10) % 12;
        if (month == 0)
            month = 12;
        f = day + ((13 * month - 1) / 5) + d + (d / 4) + (c / 4) - 2 * c;
        int res{};
        if (f < 0)
        {
            int q{-1 * f / 7};
            ++q;
            q *= -1;
            res = (f - q * 7) % 7;
        }
        else
        {
            res = f % 7;
        }
        return getDay(res);
    }
};