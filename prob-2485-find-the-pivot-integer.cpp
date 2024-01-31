class Solution
{
public:
    int pivotInteger(int n)
    {
        int pivot{1};
        int totalSum{n * (n + 1) / 2};
        for (int i{1}; i <= n; ++i)
        {
            pivot = i;
            int leftSum = i * (i + 1) / 2;
            int rightSum = totalSum - leftSum + i;
            if (leftSum == rightSum)
                return i;
        }
        return -1;
    }
};