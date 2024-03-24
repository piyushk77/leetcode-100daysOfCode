#include <string>
using namespace std;

class Solution
{
public:
    string interpret(string command)
    {
        string word{};
        for (int i{}; i < command.size(); ++i)
        {
            if (command[i] == 'G')
                word += 'G';
            else if (command[i] == '(')
            {
                ++i;
                if (command[i] == ')')
                    word += 'o';
                else
                {
                    word += "al";
                    i += 2;
                }
            }
        }
        return word;
    }
};