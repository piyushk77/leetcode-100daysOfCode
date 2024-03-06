#include <vector>
using namespace std;

class Solution
{
public:
    bool isEqual(vector<int> perm, vector<int> arr)
    {
        int n{static_cast<int>(perm.size())};
        for (int i{}; i < n; ++i)
            if (perm[i] != arr[i])
                return false;
        return true;
    }

    int reinitializePermutation(int n)
    {
        vector<int> perm;
        for (int i{}; i < n; ++i)
            perm.push_back(i);

        vector<int> arr{perm};
        vector<int> oldperm{perm};
        int count{};
        do
        {
            ++count;
            for (int i{}; i < n; ++i)
            {
                if (i % 2 == 0)
                {
                    arr[i] = perm[i / 2];
                }
                else
                {
                    arr[i] = perm[n / 2 + (i - 1) / 2];
                }
            }

            for (int i{}; i < n; ++i)
                perm[i] = arr[i];
        } while (!isEqual(perm, oldperm));
        return count;
    }
};