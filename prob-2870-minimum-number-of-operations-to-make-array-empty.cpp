#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> newNums{nums};
        int operations{};
        unordered_map<int, int> mp;
        for (int i = 0; i < newNums.size(); i++)
            mp[newNums[i]]++;

        for (auto it = mp.begin(); it != mp.end(); it++) {
            int occurence{it->second};
            if (occurence == 1)
                return -1;
            else if (occurence % 3 == 0) {
                operations += occurence / 3;
            } else if (occurence % 3 == 1) {
                operations += (occurence / 3) + 1;
            } else if (occurence % 3 == 2) {
                operations += (occurence / 3) + 1;
            }
        }
        return operations;
    }
};