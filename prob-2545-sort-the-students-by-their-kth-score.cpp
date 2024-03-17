#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insertionSort(vector<vector<int>> arr)
    {
        int i, key, key2, j;
        int n{static_cast<int>(arr.size())};
        for (i = 1; i < n; i++)
        {
            key = arr[i][0];
            key2 = arr[i][1];
            j = i - 1;
            while (j >= 0 && arr[j][0] > key)
            {
                arr[j + 1][0] = arr[j][0];
                arr[j + 1][1] = arr[j][1];
                j = j - 1;
            }
            arr[j + 1][0] = key;
            arr[j + 1][1] = key2;
        }
        return arr;
    }
    vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k)
    {
        vector<vector<int>> mat;
        for (int i{}; i < score.size(); ++i)
        {
            mat.push_back({score[i][k], i});
        }

        mat = insertionSort(mat);
        vector<vector<int>> res;
        for (int i{(static_cast<int>(mat.size())) - 1}; i >= 0; --i)
        {
            res.push_back(score[mat[i][1]]);
        }
        return res;
    }
};