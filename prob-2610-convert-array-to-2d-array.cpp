#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        vector<vector<int>> freqChart;
        vector<int> temp{nums};
        vector<vector<int>> twoDimensionalArr;

        // Prepare Frequency Chart:

        while (temp.size())
        {
            int selectedNum{temp[0]};
            int count{};
            for (int i{}; i < temp.size(); ++i)
            {
                if (temp[i] == selectedNum)
                {
                    temp.erase(temp.begin() + i);
                    ++count;
                    --i;
                }
            }
            vector<int> freq;
            freq.push_back(selectedNum);
            freq.push_back(count);
            freqChart.push_back(freq);
        }

        while (freqChart.size())
        {
            vector<int> newRow;
            for (int i{}; i < freqChart.size(); ++i)
            {
                newRow.push_back(freqChart[i][0]);
                --freqChart[i][1];
                if (!freqChart[i][1])
                {
                    freqChart.erase(freqChart.begin() + i);
                    --i;
                }
            }
            twoDimensionalArr.push_back(newRow);
        }

        return twoDimensionalArr;
    }
};