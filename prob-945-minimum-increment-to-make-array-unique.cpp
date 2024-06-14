#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        // Sort the array nums
        sort(nums.begin(), nums.end());
        // Traverse the array and keep track of the current element and the previous element
        int n{static_cast<int>(nums.size())};
        int prev{-1}, curr{};
        int count{};
        for (int i{}; i < n; ++i)
        {
            curr = nums[i];
            // If the current element is less than or equal to the previous then assign it the value of previous + 1 and increment the count as the difference
            if (curr <= prev)
            {
                count += (prev - curr + 1);
                curr = prev + 1;
            }
            prev = curr;
        }
        // Return the count
        return count;
    }
};