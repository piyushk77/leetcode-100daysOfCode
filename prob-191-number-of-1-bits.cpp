class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        unsigned int mask{0000'0000'0000'0000'0000'0000'0000'0001};
        unsigned int count{};
        for (int i{}; i < 32; ++i)
        {
            if (n & (mask << i))
                ++count;
        }
        return count;
    }
};