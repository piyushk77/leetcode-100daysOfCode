class Solution {
public:
    int passThePillow(int n, int time) {
        return ((static_cast<int>(!((time / (n - 1)) % 2))) *
                    ((time % (n - 1)) + 1) +
                (static_cast<int>((time / (n - 1)) % 2)) *
                    (n - (time % (n - 1))));
    }
};