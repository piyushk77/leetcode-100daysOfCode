class Solution {
public:
    int alternateDigitSum(int n) {
        long long sum{};
        int sign{1};
        int temp{n};
        int digitCount{};

        while (temp) {
            ++digitCount;
            temp /= 10;
        }
        if (digitCount % 2 == 0)
            sign = -1;

        while (n) {
            int digit{(n % 10) * sign};
            sum += digit;
            sign *= -1;
            n /= 10;
        }
        return sum;
    }
};