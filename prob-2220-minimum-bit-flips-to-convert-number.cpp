class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int size{sizeof(int) * 8}, count{};
        int mask{1};
        for (int i{}; i < size; ++i)
        {
            if ((static_cast<bool>(mask & goal)) ^ (static_cast<bool>(mask & start)))
                ++count;
            mask <<= 1;
        }
        return count;
    }
};