#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        vector<int> answer;
        for (int i{}; i < prices.size(); ++i)
        {
            int discount{};
            for (int j{i + 1}; j < prices.size(); ++j)
                if (prices[j] <= prices[i])
                {
                    discount = prices[j];
                    break;
                }
            answer.push_back(prices[i] - discount);
        }
        return answer;
    }
};