#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int ctoi(char ch)
    {
        switch (ch)
        {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            return -1;
        }
    }
    vector<int> extractNum(string num)
    {
        // Extracting the real part
        int sign{1};
        int i{};
        if (num[0] == '-')
        {
            sign = -1;
            i = 1;
        }
        int real{};
        while (num[i] != '+')
        {
            real = real * 10 + ctoi(num[i]);
            ++i;
        }
        real *= sign;
        ++i;

        // Extracting the imaginary part
        if (num[i] == '-')
        {
            sign = -1;
            ++i;
        }
        else
            sign = 1;
        int imag{};
        while (num[i] != 'i')
        {
            imag = imag * 10 + ctoi(num[i]);
            ++i;
        }
        imag *= sign;
        return {real, imag};
    }
    string complexNumberMultiply(string num1, string num2)
    {
        int real1{extractNum(num1)[0]};
        int real2{extractNum(num2)[0]};
        int imag1{extractNum(num1)[1]};
        int imag2{extractNum(num2)[1]};
        int real{real1 * real2 - imag1 * imag2};
        int imag{real1 * imag2 + real2 * imag1};
        string res = to_string(real);
        res += '+';
        res += to_string(imag);
        res += 'i';
        return res;
    }
};