class Solution {
public:
    int countEven(int num) {
        int count{};
        for (int i{1}; i <= num; ++i) {
            int temp{i};
            int sum{};
            while (temp) {
                int digit{temp % 10};
                sum += digit;
                temp /= 10;
            }
            if (sum % 2 == 0)
                ++count;
        }
        return count;
    }
};