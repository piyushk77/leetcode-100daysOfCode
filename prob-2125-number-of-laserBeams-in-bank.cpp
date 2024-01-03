#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int laserBeam{};
        string firstRow{}, secondRow{};
        for (int i{}; i < bank.size(); ++i) {
            if (find(bank[i].begin(), bank[i].end(), '1') != bank[i].end()) {
                if (firstRow == "") {
                    firstRow = bank[i];
                } else {
                    secondRow = bank[i];
                    int firstRowDev{}, secondRowDev{};
                    for (auto x : firstRow) {
                        if (x == '1')
                            ++firstRowDev;
                    }
                    for (auto x : secondRow) {
                        if (x == '1')
                            ++secondRowDev;
                    }
                    laserBeam += (firstRowDev * secondRowDev);
                    firstRow = secondRow;
                    secondRow = "";
                    firstRowDev = secondRowDev = 0;
                }
            }
        }
        return laserBeam;
    }
};