#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    vector<int> closestDivisors(int num)
    {
        // closest divisors for num+1
        ++num;
        vector<int> divisors({1, num});
        for (int i{1}; i <= sqrt(num); ++i)
        {
            if (num % i == 0)
            {
                int a{i};
                int b{num / i};
                if (abs(a - b) < abs(divisors[0] - divisors[1]))
                {
                    divisors[0] = a;
                    divisors[1] = b;
                }
            }
        }

        // closest divisors for num+2
        ++num;
        vector<int> divisors2({1, num});
        for (int i{1}; i <= sqrt(num); ++i)
        {
            if (num % i == 0)
            {
                int a{i};
                int b{num / i};
                if (abs(a - b) < abs(divisors2[0] - divisors2[1]))
                {
                    divisors2[0] = a;
                    divisors2[1] = b;
                }
            }
        }
        if (abs(divisors[0] - divisors[1]) < abs(divisors2[0] - divisors2[1]))
            return divisors;
        return divisors2;
    }
};