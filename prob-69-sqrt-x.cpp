class Solution {
public:
    int mySqrt(int x) {
        long long squareRoot{};
        while ((squareRoot * squareRoot) <= x)
            ++squareRoot;
        return static_cast<int>(--squareRoot);
    }
};