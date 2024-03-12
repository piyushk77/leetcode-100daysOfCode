#include <vector>
using namespace std;

class Solution
{
public:
    int findMinFib(int k, vector<long long> fibList)
    {
        if (k == 0)
            return 0;
        long long sub{};
        for (int i{}; i < fibList.size(); ++i)
        {
            if (fibList[i] > k)
            {
                sub = fibList[i - 1];
                break;
            }
        }
        int count{};
        while (k >= sub)
        {
            k -= sub;
            ++count;
        }
        return count + findMinFib(k, fibList);
    }
    int findMinFibonacciNumbers(int k)
    {
        long long prevFn{1};
        long long fn{1};
        vector<long long> fibList{1, 1};
        while (fn <= k)
        {
            fn = fn + prevFn;
            fibList.push_back(fn);
            prevFn = fn - prevFn;
        }
        return findMinFib(k, fibList);
    }
};