#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    void insertionSort(vector<int> &arr, vector<char> &ch)
    {
        int i, key, j;
        char chKey;
        int n{static_cast<int>(arr.size())};
        for (i = 1; i < n; i++)
        {
            key = arr[i];
            chKey = ch[i];
            j = i - 1;

            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                ch[j + 1] = ch[j];
                j = j - 1;
            }
            arr[j + 1] = key;
            ch[j + 1] = chKey;
        }
    }

    string frequencySort(string s)
    {
        string temp{s};
        vector<char> element;
        vector<int> freq;
        while (temp.size())
        {
            char ch{temp[0]};
            string newStr{};
            int count{};
            for (int j{}; j < temp.size(); ++j)
            {
                if (temp[j] != ch)
                    newStr += temp[j];
                else
                    count++;
            }
            temp = newStr;
            element.push_back(ch);
            freq.push_back(count);
        }
        insertionSort(freq, element);
        string result;
        for (int i{static_cast<int>(element.size() - 1)}; i >= 0; --i)
        {
            for (int j{1}; j <= freq[i]; ++j)
                result += element[i];
        }
        return result;
    }
};