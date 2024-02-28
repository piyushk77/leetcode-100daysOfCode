#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries)
    {
        vector<int> answer;
        for (int i{}; i < queries.size(); ++i)
        {
            int x0{queries[i][0]};
            int y0{queries[i][1]};
            int radius{queries[i][2]};
            int count{};
            for (int j{}; j < points.size(); ++j)
            {
                int x{points[j][0] - x0};
                int y{points[j][1] - y0};
                int distSquare{x * x + y * y};
                if (distSquare <= radius * radius)
                    ++count;
            }
            answer.push_back(count);
        }
        return answer;
    }
};