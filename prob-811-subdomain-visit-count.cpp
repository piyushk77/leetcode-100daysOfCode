#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<vector<string>> searchUpdate(vector<string> y,
                                        vector<vector<string>> domainList)
    {
        string count{y[0]};
        string domain{y[1]};
        bool found{};
        for (int i{}; i < domainList.size(); ++i)
        {
            if (domainList[i][1] == domain)
            {
                found = true;
                int num{stoi(domainList[i][0]) + stoi(count)};
                domainList[i][0] = to_string(num);
            }
        }
        if (!found)
        {
            domainList.push_back(y);
        }
        return domainList;
    }
    vector<vector<string>> getDomain(string pair)
    {
        string count{}, domain{};
        int i{};
        while (pair[i] != ' ')
        {
            count += pair[i];
            ++i;
        }
        ++i;
        int len{static_cast<int>(pair.size())};
        domain = pair.substr(i, len - i);
        int dots{};
        vector<vector<string>> domainList;
        for (auto x : domain)
            if (x == '.')
                ++dots;
        if (dots == 2)
        {
            string d1{}, d2{}, d3{};
            int c{};
            for (auto x : domain)
            {
                if (c == 0)
                {
                    d1 += x;
                }
                else if (c == 1)
                {
                    d1 += x;
                    d2 += x;
                }
                else
                {
                    d1 += x;
                    d2 += x;
                    d3 += x;
                }
                if (x == '.')
                {
                    ++c;
                }
            }
            domainList.push_back({count, d1});
            domainList.push_back({count, d2});
            domainList.push_back({count, d3});
        }
        else if (dots == 1)
        {
            string d1{}, d2{};
            int c{};
            for (auto x : domain)
            {
                if (c == 0)
                {
                    d1 += x;
                }
                else
                {
                    d1 += x;
                    d2 += x;
                }
                if (x == '.')
                {
                    ++c;
                }
            }
            domainList.push_back({count, d1});
            domainList.push_back({count, d2});
        }
        return domainList;
    }

    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        vector<vector<string>> domainList{};
        for (auto x : cpdomains)
        {
            vector<vector<string>> subDomains{getDomain(x)};
            for (auto y : subDomains)
            {
                domainList = searchUpdate(y, domainList);
            }
        }

        vector<string> res;
        for (auto x : domainList)
        {
            res.push_back(x[0] + ' ' + x[1]);
        }

        return res;
    }
};