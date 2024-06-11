#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        int n1{static_cast<int>(arr1.size())};
        int n2{static_cast<int>(arr2.size())};

        // Set priority map
        unordered_map<int, int> priority;
        for (int i{}; i < n2; ++i)
            priority.insert({arr2[i], i});

        // Make the priority pair array
        vector<pair<int, int>> arrMod(n1);
        for (int i{}; i < n1; ++i)
        {
            if (priority.find(arr1[i]) != priority.end())
                arrMod[i] = {priority[arr1[i]], arr1[i]};
            else
                arrMod[i] = {n2, arr1[i]};
        }

        // Sort the priority pair array
        sort(arrMod.begin(), arrMod.end());

        // Assign the values back to arr1
        for (int i{}; i < n1; ++i)
            arr1[i] = arrMod[i].second;

        return arr1;
    }
};