#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string alpha{};
        for (auto x : s) {
            if (isalnum(x)) {
                alpha += tolower(x);
            }
        }
        string rev{};
        for (int i{static_cast<int>(alpha.size() - 1)}; i >= 0; --i) {
            rev += alpha[i];
        }
        if (rev == alpha)
            return true;
        return false;
    }
};