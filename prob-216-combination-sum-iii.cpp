#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combSum(int k, int n, int start) {
        vector<vector<int>> comb;
        if (k == 1)
            return {{}};
        if (k == 2) {
            for (int i{start}; i <= 8; ++i) {
                int first{i};
                int second{n - first};
                if (second > first && second <= 9)
                    comb.push_back({first, second});
            }
        } else {
            for (int i{start}; i <= 10 - k; ++i) {
                vector<vector<int>> combList{combSum(k - 1, n - i, i + 1)};
                for (auto x : combList) {
                    if (x.size() != k - 1)
                        continue;
                    x.insert(x.begin(), i);
                    comb.push_back(x);
                }
            }
        }
        return comb;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        return (combSum(k, n, 1));
    }
};