class Solution
{
public:
    int numberOfSteps(int num)
    {
        int steps{};
        while (num)
        {
            if (!(num % 2))
                num /= 2;
            else
                --num;
            ++steps;
        }
        return steps;
    }
};