#include <string>
using namespace std;

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int len1{static_cast<int>(version1.size())};
        int len2{static_cast<int>(version2.size())};
        int i{}, j{};
        while (i < len1 || j < len2)
        {
            string rev1{"0"}, rev2{"0"};
            while (i < len1 && version1[i] != '.')
                rev1 += version1[i], ++i;
            while (j < len2 && version2[j] != '.')
                rev2 += version2[j], ++j;
            ++i, ++j;
            int numRev1{stoi(rev1)}, numRev2{stoi(rev2)};
            if (numRev1 < numRev2)
                return -1;
            else if (numRev1 > numRev2)
                return 1;
        }
        return 0;
    }
};