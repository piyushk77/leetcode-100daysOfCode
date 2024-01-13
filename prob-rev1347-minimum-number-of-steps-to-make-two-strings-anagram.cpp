#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    // Method to calculate the minimum steps to make two strings anagrams
    int minSteps(string s, string t)
    {
        // Arrays to store the frequency of each character in the English alphabet
        vector<int> freqS(26, 0);
        vector<int> freqT(26, 0);

        // Populate frequency arrays based on characters in strings s and t
        for (int i = 0; i < s.length(); i++)
        {
            freqS[s[i] - 'a']++; // Increment the frequency of the current character in string s
            freqT[t[i] - 'a']++; // Increment the frequency of the current character in string t
        }

        // Variable to store the count of steps needed to make the strings anagrams
        int count = 0;

        // Compare the frequency of each character in t with that in s
        for (int i = 0; i < 26; i++)
        {
            if (freqT[i] < freqS[i])
            {
                // If frequency in t is less than that in s, add the difference to the count
                count += freqS[i] - freqT[i];
            }
        }

        // Return the total count, representing the minimum steps needed
        return count;
    }
};