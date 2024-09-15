#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        vector<int> answer;
        for (auto x : queries)
        {
            int xorSum{};
            for (int i{x[0]}; i <= x[1]; ++i)
            {
                xorSum ^= arr[i];
            }
            answer.push_back(xorSum);
        }

        return answer;
    }
};