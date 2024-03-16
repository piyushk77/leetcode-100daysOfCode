#include <vector>
using namespace std;

class Solution
{
public:
    int minimumSum(int n, int k)
    {
        vector<int> avoid;
        vector<int> keep;
        int i{1}, count{};
        while (count < n)
        {
            bool canAvoid{};
            for (int x{}; x < avoid.size(); ++x)
            {
                if (avoid[x] == i)
                {
                    canAvoid = true;
                    break;
                }
            }

            if (canAvoid)
            {
                ++i;
                continue;
            }

            keep.push_back(i);
            ++count;
            avoid.push_back(k - i);
            if (i == k)
            {
                while (count < n)
                {
                    ++i;
                    keep.push_back(i);
                    ++count;
                }
            }
            ++i;
        }
        int sum{};
        for (auto x : keep)
            sum += x;
        return sum;
    }
};