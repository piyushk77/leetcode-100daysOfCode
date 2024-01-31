#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> answer;
        for (int i{}; i < 1; ++i)
        {
            bool found{};
            for (int j{i + 1}; j < temperatures.size(); ++j)
            {
                if (temperatures[j] > temperatures[i])
                {
                    answer.push_back(j - i);
                    found = true;
                    break;
                }
            }
            if (!found)
                answer.push_back(0);
        }

        for (int i{1}; i < temperatures.size(); ++i)
        {
            bool found{};
            if (temperatures[i - 1] == temperatures[i])
            {
                if (answer.back() - 1 < 0)
                {
                    answer.push_back(0);
                    continue;
                }
                answer.push_back(answer.back() - 1);
                continue;
            }
            for (int j{i + 1}; j < temperatures.size(); ++j)
            {
                if (temperatures[j] > temperatures[i])
                {
                    answer.push_back(j - i);
                    found = true;
                    break;
                }
            }
            if (!found)
                answer.push_back(0);
        }
        return answer;
    }
};