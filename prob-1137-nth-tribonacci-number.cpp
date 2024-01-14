#include <vector>
using namespace std;

class Solution
{
public:
    int tribonacci(int n)
    {
        int t0{}, t1{1}, t2{1};
        vector<int> tribSeq{t0, t1, t2};
        for (int i{3}; i <= n; ++i)
        {
            tribSeq.push_back(tribSeq[i - 1] + tribSeq[i - 2] + tribSeq[i - 3]);
        }
        return tribSeq[n];
    }
};