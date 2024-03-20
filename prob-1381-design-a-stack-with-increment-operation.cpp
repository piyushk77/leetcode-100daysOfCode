#include <vector>
using namespace std;

class CustomStack
{
    int maxElements;
    vector<int> stack;

public:
    CustomStack(int maxSize) { maxElements = maxSize; }

    void push(int x)
    {
        if (stack.size() < maxElements)
            stack.push_back(x);
    }

    int pop()
    {
        if (stack.size())
        {
            int res{stack.back()};
            stack.pop_back();
            return res;
        }
        return -1;
    }

    void increment(int k, int val)
    {
        // pop and push the current stack to temp stack
        vector<int> temp;
        while (stack.size())
        {
            temp.push_back(stack.back());
            stack.pop_back();
        }

        // pop, increment and push the k elements from temp to current stack
        for (int i{1}; i <= k && temp.size(); ++i)
        {
            int x{temp.back()};
            temp.pop_back();
            x += val;
            stack.push_back(x);
        }

        // pop and push rest of the elements of temp to current stack
        while (temp.size())
        {
            stack.push_back(temp.back());
            temp.pop_back();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */