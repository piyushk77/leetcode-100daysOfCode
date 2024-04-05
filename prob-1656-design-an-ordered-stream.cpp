#include <vector>
#include <string>
using namespace std;

class OrderedStream
{
    vector<string> hashVals;
    int ptr{};

public:
    OrderedStream(int n)
    {
        vector<string> newHash(n, "");
        hashVals = newHash;
    }

    vector<string> insert(int idKey, string value)
    {
        hashVals[idKey - 1] = value;
        vector<string> res;
        while (ptr < hashVals.size() && hashVals[ptr] != "")
        {
            res.push_back(hashVals[ptr]);
            ++ptr;
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */