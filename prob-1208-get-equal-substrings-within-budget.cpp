#include <vector>
#include <string>
#include <cmath>
using namespace std;
class Solution
{
public:
    int closeSearch(vector<long long> &arr, int l, int h, int key)
    {
        if (l > h)
            return h;
        int mid{(l + h) / 2};
        if (arr[mid] == key)
        {
            while (mid <= h && arr[mid] == key)
                ++mid;
            return mid - 1;
        }
        else if (arr[mid] < key)
            return closeSearch(arr, mid + 1, h, key);
        else
            return closeSearch(arr, l, mid - 1, key);
    }

    int equalSubstring(string s, string t, int maxCost)
    {
        int n{static_cast<int>(s.size())};
        vector<long long> prefix(n);
        prefix[0] = abs(s[0] - t[0]);
        for (int i{1}; i < n; ++i)
            prefix[i] = prefix[i - 1] + abs(s[i] - t[i]);
        int maxLen{};
        long long currentSum{};
        for (int i{}; i < n; ++i)
        {
            int index{closeSearch(prefix, i, n - 1, maxCost + currentSum)};
            int len{index - i + 1};
            if (maxLen < len)
                maxLen = len;
            currentSum = prefix[i];
        }
        return maxLen;
    }
};