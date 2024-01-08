#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution
{
public:
    int find_index(vector<int> &arr, int K)
    {
        int n{static_cast<int>(arr.size())};
        int start = 0;
        int end = n - 1;

        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (arr[mid] == K)
                return mid;
            else if (arr[mid] < K)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return end + 1;
    }

    void sortPush(vector<int> &arr, int num)
    {
        int index{find_index(arr, num)};
        arr.insert(arr.begin() + index, num);
    }

    vector<int> grayCode(int n)
    {
        vector<int> grayCode, sortedGray;
        int size{static_cast<int>(pow(2, n))};
        int prevCode{};
        grayCode.push_back(prevCode);
        sortedGray.push_back(prevCode);
        while (grayCode.size() != size)
        {
            int mask{0b0000'0000'0000'0001};
            for (int i{}; i < n; ++i)
            {
                int tempCode{prevCode ^ (mask << i)};
                if (!binary_search(sortedGray.begin(), sortedGray.end(),
                                   tempCode))
                {
                    prevCode = tempCode;
                    grayCode.push_back(prevCode);
                    sortPush(sortedGray, prevCode);
                    break;
                }
            }
        }
        return grayCode;
    }
};