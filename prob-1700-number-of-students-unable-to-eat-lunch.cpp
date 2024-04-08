#include <vector>
using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int square{}, circle{};
        int n{static_cast<int>(sandwiches.size())};
        for (auto x : students)
        {
            if (x)
                ++square;
            else
                ++circle;
        }

        if (circle < square)
        {
            for (int i{}; i < n; ++i)
            {
                if (circle <= 0)
                {
                    while (i < n && sandwiches[i] != 0)
                    {
                        --square;
                        ++i;
                    }
                    return square + circle;
                }
                if (square <= 0)
                {
                    while (i < n && sandwiches[i] != 1)
                    {
                        --circle;
                        ++i;
                    }
                    return square + circle;
                }
                if (sandwiches[i])
                    --square;
                else
                    --circle;
            }
        }
        else
        {
            for (int i{}; i < n; ++i)
            {
                if (square <= 0)
                {
                    while (i < n && sandwiches[i] != 1)
                    {
                        --circle;
                        ++i;
                    }
                    return square + circle;
                }
                if (circle <= 0)
                {
                    while (i < n && sandwiches[i] != 0)
                    {
                        --square;
                        ++i;
                    }
                    return square + circle;
                }
                if (sandwiches[i])
                    --square;
                else
                    --circle;
            }
        }
        return square + circle;
    }
};