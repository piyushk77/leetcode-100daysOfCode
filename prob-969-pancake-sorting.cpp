#include <vector>
using namespace std;

class Solution
{
    vector<int> answer;

public:
    void pancake(vector<int> arr)
    {
        if (arr.size() == 1)
            return;
        int max{}, index{};
        for (int i{}; i < arr.size(); ++i)
        {
            if (max < arr[i])
            {
                max = arr[i];
                index = i;
            }
        }
        answer.push_back(index + 1);
        // perform pancake flip for k = index:
        vector<int> subArr;
        for (int i{index}; i >= 0; --i)
            subArr.push_back(arr[i]);
        for (int i{}; i < subArr.size(); ++i)
            arr[i] = subArr[i];
        subArr.clear();
        // perform pancake flip for k = arr.length:
        index = static_cast<int>(arr.size()) - 1;
        answer.push_back(index + 1);
        for (int i{index}; i >= 0; --i)
            subArr.push_back(arr[i]);
        for (int i{}; i < subArr.size(); ++i)
            arr[i] = subArr[i];
        subArr = arr;
        subArr.pop_back();
        pancake(subArr);
    }
    vector<int> pancakeSort(vector<int> &arr)
    {
        pancake(arr);
        return answer;
    }
};