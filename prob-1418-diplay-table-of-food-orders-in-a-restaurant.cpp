#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int getIndex(vector<string> &items, string item)
    {
        for (int i{}; i < items.size(); ++i)
            if (items[i] == item)
                return i;
        return -1;
    }
    bool isPresent(vector<string> &items, string item)
    {
        for (auto x : items)
            if (x == item)
                return true;
        return false;
    }
    static bool comparef(string a, string b)
    {
        if (stoi(a) < stoi(b))
            return true;
        return false;
    }
    vector<vector<string>> displayTable(vector<vector<string>> &orders)
    {
        vector<string> foodItems{"Table"}, tableNo{};
        for (auto x : orders)
        {
            if (!isPresent(foodItems, x[2]))
                foodItems.push_back(x[2]);
            if (!isPresent(tableNo, x[1]))
                tableNo.push_back(x[1]);
        }
        sort(foodItems.begin() + 1, foodItems.end());
        sort(tableNo.begin(), tableNo.end(), comparef);
        vector<vector<string>> display{foodItems};
        int m{static_cast<int>(foodItems.size())};
        for (auto x : tableNo)
        {
            vector<string> temp(m, "0");
            temp[0] = x;
            display.push_back(temp);
        }

        for (auto x : orders)
        {
            int col{getIndex(foodItems, x[2])};
            int row{getIndex(tableNo, x[1]) + 1};
            int num{stoi(display[row][col])};
            ++num;
            display[row][col] = to_string(num);
        }

        return display;
    }
};