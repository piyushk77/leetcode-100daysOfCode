class Solution {
public:
    bool isThree(int n) {
        int count {};
        for(int i {1}; i <= n; ++i){
            if(n%i == 0)
                ++count;
            if(count > 3)
                return false;
        }
        if(count == 3)
            return true;
        return false;
    }
};