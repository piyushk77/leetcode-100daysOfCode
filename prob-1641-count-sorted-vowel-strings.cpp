class Solution
{
public:
    int countVowelStrings(int n)
    {
        int a{5}, b{4}, c{3}, d{2};
        for (int i{1}; i < n; ++i)
        {
            d += 1;
            c += d;
            b += c;
            a += b;
        }
        return a;
    }
};