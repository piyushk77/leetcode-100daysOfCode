#include <vector>
using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        vector<int> stack;
        int i{-1};
        int j{};
        while ((i < static_cast<int>(pushed.size())) &&
               (j < static_cast<int>(popped.size())))
        {
            do
            {
                ++i;
                if (i >= pushed.size())
                    return false;
                stack.push_back(pushed[i]);
            } while (pushed[i] != popped[j]);

            while (j < popped.size() && stack.size() &&
                   stack.back() == popped[j])
            {
                stack.pop_back();
                ++j;
            }
        }
        if (stack.size())
            return false;
        return true;
    }
};