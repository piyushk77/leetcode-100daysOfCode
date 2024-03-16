class Solution
{
public:
    int numTrees(int n)
    {
        if (n == 1 || n == 0)
            return 1;
        int res{};
        for (int i{1}; i <= n; ++i)
        {
            int a{numTrees(i - 1)};
            int b{numTrees(n - i)};
            res += (a * b);
        }
        return res;
    }
};