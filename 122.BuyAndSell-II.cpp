#include <iostream>
#include <vector>
using namespace std;
// Runtime 4 ms. Beats 68.32% of users with C++
// Memory 15.38 MB. Beats 92.18% of users with C+
int maxProfit(vector<int> &prices)
{
    int profit = 0;
    for (int i = prices.size() - 2; i >= 0; i--)
    {
        if (prices[i] < prices[i + 1])
            profit += prices[i + 1] - prices[i];
    }
    return profit;
}
int main()
{
    vector<int> prices{7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;
    return 0;
}