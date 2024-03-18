#include <vector>
using namespace std;

class Solution
{
public:
    int commonCount(vector<int> arrA, vector<int> arrB)
    {
        int count{};
        for (int i{}; i < arrA.size(); ++i)
        {
            if (arrA[i] != 0 && arrA[i] == arrB[i])
                ++count;
        }
        return count;
    }
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        int n{static_cast<int>(A.size())};
        vector<int> answer;
        vector<int> hashA(n), hashB(n);
        for (int i{}; i < n; ++i)
        {
            ++hashA[A[i] - 1];
            ++hashB[B[i] - 1];
            answer.push_back(commonCount(hashA, hashB));
        }
        return answer;
    }
};