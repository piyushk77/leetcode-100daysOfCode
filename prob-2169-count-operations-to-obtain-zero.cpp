class Solution
{
public:
    int countOperations(int num1, int num2)
    {
        int operations{};
        while (num1 && num2)
        {
            if (num1 >= num2)
                num1 -= num2;
            else
                num2 -= num1;
            ++operations;
        }
        return operations;
    }
};