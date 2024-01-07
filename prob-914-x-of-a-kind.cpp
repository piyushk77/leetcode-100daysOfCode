#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int gcd(int a, int b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    int findGCD(vector<int>& arr) {
        int result = arr[0];
        int n {static_cast<int>(arr.size())};
        for (int i = 1; i < n; i++) {
            result = gcd(arr[i], result);

            if (result == 1) {
                return 1;
            }
        }
        return result;
    }

    bool hasGroupsSizeX(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int selectedNum{deck[0]};
        int freq{};
        vector<int> freqChart;

        for (int i{}; i < deck.size(); ++i) {
            if (selectedNum == deck[i]) {
                ++freq;
            } else {
                freqChart.push_back(freq);
                freq = 1;
                selectedNum = deck[i];
            }
        }

        freqChart.push_back({freq});

        // find the x
        int x {findGCD(freqChart)};

        if (x == 1) {
            return false;
        }

        return true;
    }
};