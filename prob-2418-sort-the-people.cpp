#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        int max{};
        for (auto x : heights)
        {
            if (max < x)
                max = x;
        }
        vector<int> hashHeight(max + 1, -1);
        for (int i{}; i < heights.size(); ++i)
        {
            hashHeight[heights[i]] = i;
        }
        vector<string> sortNames;
        for (int i{static_cast<int>(hashHeight.size()) - 1}; i >= 0; --i)
        {
            if (hashHeight[i] != -1)
                sortNames.push_back(names[hashHeight[i]]);
        }
        return sortNames;
    }
};