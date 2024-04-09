#include <vector>
using namespace std;

class Solution
{
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right)
    {
        int maxLeft{};
        for (auto x : left)
            if (maxLeft < x)
                maxLeft = x;
        int minRight{n};
        for (auto x : right)
            if (minRight > x)
                minRight = x;
        int maxDistance{};
        if (maxLeft > (n - minRight))
            maxDistance = maxLeft;
        else
            maxDistance = n - minRight;
        return maxDistance;
    }
};