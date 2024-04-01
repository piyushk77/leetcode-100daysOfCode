#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int getCharIndex(char ch)
    {
        switch (ch)
        {
        case 'a':
            return 0;
        case 'b':
            return 1;
        case 'c':
            return 2;
        case 'd':
            return 3;
        case 'e':
            return 4;

        case 'f':
            return 5;
        case 'g':
            return 6;
        case 'h':
            return 7;
        case 'i':
            return 8;
        case 'j':
            return 9;

        case 'k':
            return 10;
        case 'l':
            return 11;
        case 'm':
            return 12;
        case 'n':
            return 13;
        case 'o':
            return 14;

        case 'p':
            return 15;
        case 'q':
            return 16;
        case 'r':
            return 17;
        case 's':
            return 18;
        case 't':
            return 19;

        case 'u':
            return 20;
        case 'v':
            return 21;
        case 'w':
            return 22;
        case 'x':
            return 23;
        case 'y':
            return 24;

        case 'z':
            return 25;

        default:
            return -1;
        }
    }
    string getMorse(string word)
    {
        vector<string> morseTable{
            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
            "....", "..", ".---", "-.-", ".-..", "--", "-.",
            "---", ".--.", "--.-", ".-.", "...", "-", "..-",
            "...-", ".--", "-..-", "-.--", "--.."};
        string morse{};
        for (auto x : word)
        {
            morse += morseTable[getCharIndex(x)];
        }
        return morse;
    }
    int uniqueMorseRepresentations(vector<string> &words)
    {
        vector<string> morse;
        for (auto word : words)
            morse.push_back(getMorse(word));
        int count{};
        for (int i{}; i < morse.size(); ++i)
        {
            if (morse[i] == "$")
                continue;
            ++count;
            string key{morse[i]};
            for (int j{i}; j < morse.size(); ++j)
            {
                if (key == morse[j])
                    morse[j] = "$";
            }
        }
        return count;
    }
};