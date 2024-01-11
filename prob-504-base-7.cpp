#include <string>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        string flag {};
        if(num < 0){
            flag = "-";
            num *= -1;
        }
        if(num == 0){
            return "0";
        }
        string newBase {};
        while(num){
            int rem {num % 7};
            num /= 7;
            newBase = to_string(rem) + newBase;
        }

        newBase = flag + newBase;
        return newBase;
    }
};