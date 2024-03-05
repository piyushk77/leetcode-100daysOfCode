#include <string>
using namespace std;

class Solution
{
public:
    int minimumLength(string s)
    {
        int front{}, back{static_cast<int>(s.size()) - 1};
        while (front < back)
        {
            if (s[front] != s[back])
                return (back - front + 1);
            char ch{s[front]};
            while (s[front] == ch)
            {
                ++front;
            }
            if (front > back)
                return 0;
            while (s[back] == ch)
            {
                --back;
            }
        }
        return (back - front + 1);
    }
};