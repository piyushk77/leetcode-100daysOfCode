#include <string>
using namespace std;
class Solution
{
public:
    string addBinary(string a, string b)
    {
        if (a.length() != b.length())
        {
            int numOfZeros{};
            if (a.length() > b.length())
                numOfZeros = a.length() - b.length();
            else
                numOfZeros = b.length() - a.length();

            string leadZeros{};
            for (int i{1}; i <= numOfZeros; ++i)
                leadZeros += "0";

            if (a.length() > b.length())
                b = leadZeros + b;
            else
                a = leadZeros + a;
        }
        char carry = '0';
        string sum{};
        for (int i{static_cast<int>(a.length() - 1)}; i >= 0; --i)
        {
            if (a[i] == '0' && b[i] == '0' && carry == '0')
            {
                sum = '0' + sum;
            }
            else if (a[i] == '0' && b[i] == '0' && carry == '1')
            {
                sum = '1' + sum;
                carry = '0';
            }
            else if (a[i] == '0' && b[i] == '1' && carry == '0')
            {
                sum = '1' + sum;
                carry = '0';
            }
            else if (a[i] == '0' && b[i] == '1' && carry == '1')
            {
                sum = '0' + sum;
                carry = '1';
            }
            else if (a[i] == '1' && b[i] == '0' && carry == '0')
            {
                sum = '1' + sum;
                carry = '0';
            }
            else if (a[i] == '1' && b[i] == '0' && carry == '1')
            {
                sum = '0' + sum;
                carry = '1';
            }
            else if (a[i] == '1' && b[i] == '1' && carry == '0')
            {
                sum = '0' + sum;
                carry = '1';
            }
            else if (a[i] == '1' && b[i] == '1' && carry == '1')
            {
                sum = '1' + sum;
                carry = '1';
            }
        }

        if (carry == '1')
        {
            sum = '1' + sum;
        }

        return sum;
    }
};