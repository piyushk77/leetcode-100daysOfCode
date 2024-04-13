class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int mask{1};
        int count{};
        for (int i{}; i < sizeof(int) * 8; ++i)
        {
            bool bitA{static_cast<bool>(a & (mask << i))};
            bool bitB{static_cast<bool>(b & (mask << i))};
            bool bitC{static_cast<bool>(c & (mask << i))};
            if ((bitA || bitB) ^ bitC)
            {
                ++count;
                if (bitA && bitB)
                    ++count;
            }
        }
        return count;
    }
};