#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> intersection;
        unordered_map<int, int> umap;
        for (auto x : nums1)
            umap[x]++;
        for (auto x : nums2)
        {
            if (umap.find(x) != umap.end() && umap[x])
            {
                intersection.push_back(x);
                umap[x]--;
            }
        }
        return intersection;
    }
};