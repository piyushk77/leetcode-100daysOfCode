#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        int n{static_cast<int>(boxes.size())};
        vector<int> answer;
        for (int i{}; i < n; ++i)
        {
            int ans{};
            for (int j{}; j < n; ++j)
            {
                if (boxes[j] == '1')
                    ans += abs(j - i);
            }
            answer.push_back(ans);
        }
        return answer;
    }
};