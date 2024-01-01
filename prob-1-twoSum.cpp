#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        for (int i{}; i < nums.size(); ++i) {
            for (int j{}; j < nums.size(); ++j) {
                if (j == i)
                    continue;
                if (nums[i] + nums[j] == target) {
                    indices.push_back(i);
                    indices.push_back(j);
                    return indices;
                }
            }
        }
        return indices;
    }
};