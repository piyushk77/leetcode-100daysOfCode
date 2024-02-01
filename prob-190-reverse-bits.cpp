class Solution
{
public:
    unsigned int reverseBits(unsigned int n)
    {
        unsigned int rev{};
        unsigned int mask{1};
        for (int i{}; i < 32; ++i)
        {
            unsigned int bit{n & (mask << i)};
            if (bit)
                rev = (rev | (mask << 31 - i));
        }
        return rev;
    }
};