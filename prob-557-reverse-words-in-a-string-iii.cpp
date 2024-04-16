#include <string>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string word{""};
        string sentence{""};
        for (auto x : s)
        {
            if (x == ' ')
            {
                sentence = sentence + word + x;
                word = "";
                continue;
            }
            word = x + word;
        }
        sentence += word;
        return sentence;
    }
};