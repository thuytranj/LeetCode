#include <iostream>
#include <vector>
using namespace std;
// Runtime 59 ms. Beats 98.79% of users with C++
// Memory 95.98 MB. Beats 8.66% of users with C+
int maxProfit(vector<int> &prices)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int min = prices[0], profit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] - min > profit)
            profit = prices[i] - min;
        if (prices[i] < min)
            min = prices[i];
    }
    return profit;
}
int main (){
    vector<int> prices{7, 1, 5, 3, 6, 4};
    cout<<maxProfit(prices)<<endl;
    return 0;
}