#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string sortSentence(string s)
    {
        vector<string> words(10);
        int num{};
        string word{};
        for (auto x : s)
        {
            if (isdigit(x))
            {
                string temp{x};
                num = stoi(temp);
                words[num] = word;
                word = "";
                continue;
            }
            if (x != ' ')
                word += x;
        }
        string sentence{};
        for (int i{}; i < words.size(); ++i)
        {
            if (words[i] != "")
                sentence += " " + words[i];
        }
        sentence.erase(0, 1);
        return sentence;
    }
};