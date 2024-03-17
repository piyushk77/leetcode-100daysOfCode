#include <vector>
using namespace std;

class Solution
{
public:
    inline int find(int key, vector<int> arr)
    {
        for (int i{}; i < arr.size(); ++i)
            if (arr[i] == key)
                return i;
        return -1;
    }
    vector<int> processQueries(vector<int> &queries, int m)
    {
        vector<int> perm;
        for (int i{1}; i <= m; ++i)
            perm.push_back(i);
        vector<int> res;
        for (auto q : queries)
        {
            vector<int> newPerm{q};
            int index{find(q, perm)};
            res.push_back(index);
            for (auto x : perm)
            {
                if (x == q)
                    continue;
                newPerm.push_back(x);
            }
            perm = newPerm;
        }

        return res;
    }
};