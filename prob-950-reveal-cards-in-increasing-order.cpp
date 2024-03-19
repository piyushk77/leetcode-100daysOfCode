#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        sort(deck.begin(), deck.end());
        vector<int> res;
        for (int i{static_cast<int>(deck.size()) - 1}; i >= 0; --i)
        {
            res.insert(res.begin(), deck[i]);
            if (i == 0)
                break;
            int last{res.back()};
            res.pop_back();
            res.insert(res.begin(), last);
        }
        return res;
    }
};