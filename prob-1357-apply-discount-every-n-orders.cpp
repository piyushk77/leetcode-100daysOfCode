#include <vector>
using namespace std;

class Cashier
{
    const int SIZE{200};
    int custCount{}, nth{}, disc{};
    vector<int> prods;

public:
    Cashier(int n, int discount, vector<int> &products, vector<int> &prices)
    {
        nth = n;
        disc = discount;
        vector<int> temp(SIZE + 1);
        prods = temp;
        for (int i{}; i < products.size(); ++i)
            prods[products[i]] = prices[i];
    }

    double getBill(vector<int> product, vector<int> amount)
    {
        ++custCount;
        bool applyDiscount{};
        if (custCount == nth)
        {
            applyDiscount = true;
            custCount = 0;
        }

        double bill{};
        for (int i{}; i < product.size(); ++i)
        {
            bill += amount[i] * (prods[product[i]]);
        }

        bill = (bill * (100 - (static_cast<int>(applyDiscount) * disc))) / 100;
        return bill;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */