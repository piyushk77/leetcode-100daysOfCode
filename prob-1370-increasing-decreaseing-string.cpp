#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    string sortString(string s)
    {
        int n{static_cast<int>(s.length())};
        unordered_map<char, int> freqs;
        for (auto x : s)
            freqs[x]++;
        char offset{'a' - 1};

        string result{};
        int count{};
        while (count < n)
        {
            char smallest{};
            for (int a{1}; a <= 26; ++a)
            {
                if (freqs.find(a + offset) != freqs.end() &&
                    freqs[a + offset])
                {
                    --freqs[a + offset];
                    smallest = a + offset;
                    break;
                }
            }

            result += smallest;
            ++count;
            if (count >= n)
                break;
            bool flag{true};
            while (flag)
            {
                flag = false;
                for (int a{smallest + 1 - offset}; a <= 26; ++a)
                {
                    if (freqs.find(a + offset) != freqs.end() &&
                        freqs[a + offset])
                    {
                        --freqs[a + offset];
                        smallest = a + offset;
                        flag = true;
                        break;
                    }
                }
                if (flag)
                {
                    result += smallest;
                    ++count;
                }
            }
            if (count >= n)
                break;
            char largest{};
            for (int a{26}; a >= 1; --a)
            {
                if (freqs.find(a + offset) != freqs.end() &&
                    freqs[a + offset])
                {
                    --freqs[a + offset];
                    largest = a + offset;
                    break;
                }
            }
            result += largest;
            ++count;
            if (count >= n)
                break;
            flag = true;
            while (flag)
            {
                flag = false;
                for (int a{largest - 1 - offset}; a >= 1; --a)
                {
                    if (freqs.find(a + offset) != freqs.end() &&
                        freqs[a + offset])
                    {
                        --freqs[a + offset];
                        largest = a + offset;
                        flag = true;
                        break;
                    }
                }
                if (flag)
                {
                    result += largest;
                    ++count;
                }
            }
            if (count >= n)
                break;
        }
        return result;
    }
};