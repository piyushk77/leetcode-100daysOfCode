#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string triangleType(vector<int> &nums)
    {
        int a{nums[0]};
        int b{nums[1]};
        int c{nums[2]};

        if ((a >= b + c) || (b >= a + c) || (c >= a + b))
            return "none";

        if (a == b && b == c)
            return "equilateral";

        if (a != b && a != c && b != c)
            return "scalene";

        else
            return "isosceles";
    }
};