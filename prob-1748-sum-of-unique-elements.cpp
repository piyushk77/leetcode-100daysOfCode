#include <vector>
using namespace std;

class Solution
{
public:
    int sumOfUnique(vector<int> &nums)
    {
        const int SIZE{100};
        vector<int> hash(SIZE + 1);
        for (auto x : nums)
            ++hash[x];
        int sum{};
        for (int i{}; i < hash.size(); ++i)
            if (hash[i] == 1)
                sum += i;
        return sum;
    }
};