#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int numTime(string time)
  {
    int hrs{static_cast<int>(stoi(time.substr(0, 2)))};
    int min{static_cast<int>(stoi(time.substr(3, 2)))};
    min += hrs * 60;
    return min;
  }
  int findMinDifference(vector<string> &timePoints)
  {
    const int n{static_cast<int>(timePoints.size())};
    vector<int> timeValues(n);
    for (int i{}; i < n; ++i)
      timeValues[i] = numTime(timePoints[i]);
    sort(timeValues.begin(), timeValues.end());
    int minDiff{abs((24 * 60) + timeValues[0] - timeValues[n - 1])};
    for (int i{1}; i < n; ++i)
    {
      if (minDiff > abs(timeValues[i] - timeValues[i - 1]))
        minDiff = abs(timeValues[i] - timeValues[i - 1]);
    }
    return minDiff;
  }
};