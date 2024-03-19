#include <vector>
#include <string>
using namespace std;

class BrowserHistory
{
    vector<string> history;
    vector<string> stack;

public:
    BrowserHistory(string homepage)
    {
        // cout << "Set homepage to : " << homepage << endl << endl;
        history.push_back(homepage);
    }

    void visit(string url)
    {
        // cout << "Visiting " << url << " from current page : " <<
        // history.back() << endl;
        history.push_back(url);
        // cout << "Clearing forward history" << endl << endl;
        stack = {};
    }

    string back(int steps)
    {
        if (steps >= history.size())
            steps = static_cast<int>(history.size()) - 1;
        while (steps)
        {
            // cout << "Pop " << history.back() << " and push it to stack" <<
            // endl;
            stack.push_back(history.back());
            // cout << "Stack top is now : " << stack.back() << endl << endl;
            history.pop_back();
            --steps;
        }
        return history.back();
    }

    string forward(int steps)
    {
        if (stack.size() == 0)
            return history.back();
        if (steps > stack.size())
            steps = stack.size();
        while (steps)
        {
            // cout << "Pop " << stack.back() << " and push it to history" <<
            // endl;
            history.push_back(stack.back());
            // cout << "History top is now : " << history.back() << endl <<
            // endl;
            stack.pop_back();
            --steps;
        }
        return history.back();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */