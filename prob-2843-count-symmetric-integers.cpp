class Solution
{
public:
    bool evenDigits(int n)
    {
        int digits{};
        while (n)
        {
            n /= 10;
            ++digits;
        }
        if (digits % 2 == 0)
            return true;
        return false;
    }

    bool isSymmetric(int n)
    {
        int temp{n};
        int digits{};
        while (temp)
        {
            temp /= 10;
            ++digits;
        }

        int firstSum{}, secondSum{};

        for (int i{1}; i <= digits / 2; ++i)
        {
            int digit{n % 10};
            firstSum += digit;
            n /= 10;
        }

        for (int i{1}; i <= digits / 2; ++i)
        {
            int digit{n % 10};
            secondSum += digit;
            n /= 10;
        }
        if (firstSum == secondSum)
            return true;
        return false;
    }

    int countSymmetricIntegers(int low, int high)
    {
        int count{};
        for (int i{low}; i <= high; ++i)
        {
            if (evenDigits(i))
            {
                if (isSymmetric(i))
                    ++count;
            }
        }
        return count;
    }
};