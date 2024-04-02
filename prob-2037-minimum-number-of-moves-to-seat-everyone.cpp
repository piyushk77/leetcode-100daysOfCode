#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution
{
public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students)
    {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int moves{};
        for (int i{}; i < seats.size(); ++i)
        {
            moves += abs(seats[i] - students[i]);
        }
        return moves;
    }
};