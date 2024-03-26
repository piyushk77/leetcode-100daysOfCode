#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> decode(vector<int> &encoded, int first)
    {
        int n{static_cast<int>(encoded.size()) + 1};
        vector<int> decoded(n);
        decoded[0] = first;
        for (int i{1}; i < n; ++i)
        {
            decoded[i] = decoded[i - 1] ^ encoded[i - 1];
        }
        return decoded;
    }
};