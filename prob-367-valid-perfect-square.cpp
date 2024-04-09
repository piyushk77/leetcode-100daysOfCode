class Solution {
public:
    bool isPerfectSquare(int num) {
        long long i{1};
        for (; i * i < num; ++i)
            ;
        if (i * i == num)
            return true;
        return false;
    }
};