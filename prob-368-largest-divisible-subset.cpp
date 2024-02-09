#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        vector<vector<int>> answers;
        for (int i{}; i < nums.size(); ++i)
        {
            vector<int> answer;
            answer.push_back(nums[i]);
            for (int j{}; j < nums.size(); ++j)
            {
                bool flag{true};
                if (j == i)
                    continue;
                for (int k{}; k < answer.size(); ++k)
                {
                    if (nums[j] % answer[k] != 0 && answer[k] % nums[j] != 0)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    answer.push_back(nums[j]);
                }
            }
            answers.push_back(answer);
        }
        int maxSize{}, maxIndex{};
        for (int i{}; i < answers.size(); ++i)
        {
            if (maxSize < answers[i].size())
            {
                maxSize = answers[i].size();
                maxIndex = i;
            }
        }
        return answers[maxIndex];
    }
};