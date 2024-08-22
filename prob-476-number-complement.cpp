class Solution
{
public:
    int findComplement(int num)
    {
        // find the starting bit
        unsigned mask{1};
        short sBit{-1};
        for (int i{31}; i >= 0; --i)
        {
            if (num & (mask << i))
            {
                sBit = i;
                break;
            }
        }
        if (sBit == -1)
            return -1;

        // generate new mask
        unsigned cover{};
        for (int i{sBit}; i >= 0; --i)
            cover = cover | (mask << i);

        // invert num
        num = ~num;

        return cover & num;
    }
};