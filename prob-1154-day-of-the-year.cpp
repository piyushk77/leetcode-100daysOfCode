#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isLeapYear(int year)
    {
        if (year % 4 == 0)
        {
            if (year % 100 != 0)
                return true;
            else if (year % 400 == 0)
                return true;
        }
        return false;
    }
    int dayOfYear(string date)
    {
        vector<int> daysInMonth{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        string yearStr{date.substr(0, 4)};
        int year{atoi(yearStr.data())};

        string monthStr{date.substr(5, 2)};
        int month{atoi(monthStr.data())};

        string dayStr{date.substr(8, 2)};
        int day{atoi(dayStr.data())};

        int daysTillMonth{};
        for (int i{}; i < month; ++i)
        {
            daysTillMonth += daysInMonth[i];
        }

        int dayOfYear = daysTillMonth + day;

        if (month > 2 && isLeapYear(year))
        {
            ++dayOfYear;
        }
        return dayOfYear;
    }
};