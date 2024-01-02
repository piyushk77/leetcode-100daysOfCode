#include <string>
using namespace std;
class Solution
{
public:
    string intToRoman(int num)
    {
        int temp{num};
        int ones{temp % 10};
        temp /= 10;
        int tens{temp % 10};
        temp /= 10;
        int hundreds{temp % 10};
        temp /= 10;
        int thousands{temp % 10};

        string romanThousands{}, romanHundreds{}, romanTens{}, romanOnes{};
        if (thousands)
        {
            for (int i{1}; i <= thousands; ++i)
            {
                romanThousands += "M";
            }
        }

        if (hundreds)
        {
            if (hundreds < 5)
            {
                if (hundreds == 4)
                    romanHundreds = "CD";
                else
                    for (int i{1}; i <= hundreds; ++i)
                    {
                        romanHundreds += "C";
                    }
            }
            else
            {
                if (hundreds == 9)
                    romanHundreds = "CM";
                else
                {
                    romanHundreds = "D";
                    for (int i{1}; i <= hundreds - 5; ++i)
                    {
                        romanHundreds += "C";
                    }
                }
            }
        }

        if (tens)
        {
            if (tens < 5)
            {
                if (tens == 4)
                    romanTens = "XL";
                else
                    for (int i{1}; i <= tens; ++i)
                    {
                        romanTens += "X";
                    }
            }
            else
            {
                if (tens == 9)
                    romanTens = "XC";
                else
                {
                    romanTens = "L";
                    for (int i{1}; i <= tens - 5; ++i)
                    {
                        romanTens += "X";
                    }
                }
            }
        }

        if (ones)
        {
            if (ones < 5)
            {
                if (ones == 4)
                    romanOnes = "IV";
                else
                    for (int i{1}; i <= ones; ++i)
                    {
                        romanOnes += "I";
                    }
            }
            else
            {
                if (ones == 9)
                    romanOnes = "IX";
                else
                {
                    romanOnes = "V";
                    for (int i{1}; i <= ones - 5; ++i)
                    {
                        romanOnes += "I";
                    }
                }
            }
        }

        string roman = romanThousands + romanHundreds + romanTens + romanOnes;
        return roman;
    }
};