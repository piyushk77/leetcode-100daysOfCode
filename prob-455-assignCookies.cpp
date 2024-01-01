#include <vector>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int childCount{};

        for (int j{}; j < s.size(); ++j) {
            bool firstCompare{true}, isChildSelected{};
            int minimum{}, giveChild{};
            for (int i{}; i < g.size(); ++i) {
                if (s[j] < g[i])
                    continue;
                if (firstCompare) {
                    minimum = s[j] - g[i];
                    firstCompare = false;
                }
                if (s[j] - g[i] <= minimum) {
                    minimum = s[j] - g[i];
                    giveChild = i;
                    isChildSelected = true;
                }
            }
            if (isChildSelected) {
                g.erase(g.begin() + giveChild);
                ++childCount;
            }
        }
        return childCount;
    }
};