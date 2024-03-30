#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool areEq(string first, string second)
    {
        vector<char> oddFirst, oddSecond;
        vector<char> evenFirst, evenSecond;
        for (int i{}; i < first.size(); i += 2)
        {
            oddFirst.push_back(first[i]);
            oddSecond.push_back(second[i]);
        }

        for (int i{1}; i < first.size(); i += 2)
        {
            evenFirst.push_back(first[i]);
            evenSecond.push_back(second[i]);
        }

        sort(oddFirst.begin(), oddFirst.end());
        sort(oddSecond.begin(), oddSecond.end());
        sort(evenFirst.begin(), evenFirst.end());
        sort(evenSecond.begin(), evenSecond.end());

        for (int i{}; i < oddFirst.size(); ++i)
            if (oddFirst[i] != oddSecond[i])
                return false;
        for (int i{}; i < evenFirst.size(); ++i)
            if (evenFirst[i] != evenSecond[i])
                return false;
        return true;
    }

    int numSpecialEquivGroups(vector<string> &words)
    {
        int groups{};
        for (int i{}; i < words.size(); ++i)
        {
            if (words[i] == "$")
                continue;
            string key{words[i]};
            words[i] = "$";
            for (int j{i}; j < words.size(); ++j)
            {
                if (words[j] == "$")
                    continue;
                if (areEq(key, words[j]))
                {
                    words[j] = "$";
                }
            }
            ++groups;
        }
        return groups;
    }
};