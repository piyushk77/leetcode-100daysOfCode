#include <vector>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int first{};
        int last{static_cast<int>(arr.size())};
        int mid{(first + last) / 2};

        while (!(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]))
        {
            if (arr[mid] < arr[mid + 1])
            {
                first = mid;
                mid = (mid + last) / 2;
            }
            else
            {
                last = mid;
                mid = (first + mid) / 2;
            }
        }

        return mid;
    }
};