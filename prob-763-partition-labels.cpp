#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int lastOccur(int index, string s)
    {
        char key{s[index]};
        for (int i{index + 1}; i < s.size(); ++i)
        {
            if (s[i] == key)
                return i;
        }
        return index;
    }
    vector<int> partitionLabels(string s)
    {
        vector<int> partLen;
        int start{};
        while (start < s.length())
        {
            int max{lastOccur(start, s)};
            int count{};
            int i{start};
            for (; i <= max; ++i)
            {
                int temp{lastOccur(i, s)};
                if (max < temp)
                    max = temp;
                ++count;
            }
            start = i;
            partLen.push_back(count);
        }
        return partLen;
    }
};