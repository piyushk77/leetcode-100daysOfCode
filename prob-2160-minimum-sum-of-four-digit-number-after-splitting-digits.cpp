#include <string>
using namespace std;

class Solution
{
public:
    int combinations(string num)
    {
        int result{9999};
        for (int i{}; i < num.size(); ++i)
        {
            for (int j{}; j < num.size(); ++j)
            {
                if (j == i)
                    continue;
                for (int k{}; k < num.size(); ++k)
                {
                    if (k == i || k == j)
                        continue;
                    for (int l{}; l < num.size(); ++l)
                    {
                        if (l == i || l == j || l == k)
                            continue;
                        string newNum{};
                        newNum += num[i];
                        newNum += num[j];
                        newNum += num[k];
                        newNum += num[l];
                        for (int m{1}; m < newNum.size(); ++m)
                        {
                            string first{newNum.substr(0, m)};
                            string second{newNum.substr(m, 4 - m)};
                            int num1{stoi(first)};
                            int num2{stoi(second)};
                            if (result > num1 + num2)
                                result = num1 + num2;
                        }
                    }
                }
            }
        }
        return result;
    }
    int minimumSum(int num) { return combinations(to_string(num)); }
};