class Solution {
public:
    int returnSum(int num) {
        int temp{num};
        int digits{};
        while (temp) {
            temp /= 10;
            ++digits;
        }
        temp = num;
        int sum{};
        for (int i{}; i < digits; ++i) {
            int digit = temp % 10;
            sum += digit * digit;
            temp /= 10;
        }

        return sum;
    }
    bool isHappy(int n) {
        int num{n};
        while (num && num != 1) {
            num = returnSum(num);
            switch (num) {
            case 17:
            case 50:
            case 25:
            case 29:
            case 85:
            case 4:
            case 16:
            case 37:
            case 58:
            case 89:
            case 145:
            case 42:
            case 20:
                return false;
                break;
            default:
                continue;
            }
        }
        return true;
    }
};