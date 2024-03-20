#include <iostream>
#include <vector>
using namespace std;
// Runtime 45 ms. Beats 99.79% of users with C++
// Memory 83.55 MB. Beats 67.65% of users with C++

int maxProfit(vector<int> &prices)
{
    int min = prices[0];
    vector<int> left;
    left.resize(prices.size());
    left[0] = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        left[i] = max(prices[i] - min, left[i - 1]);
        if (prices[i] < min)
            min = prices[i];
    }
    int maxP = prices[prices.size() - 1];
    vector<int> right;
    right.resize(prices.size());
    right[prices.size() - 1] = 0;
    for (int i = prices.size() - 2; i >= 0; i--)
    {
        right[i] = max(maxP - prices[i], right[i + 1]);
        if (prices[i] > maxP)
            maxP = prices[i];
    }
    int max = right[0] + left[0];
    for (int i = 1; i < left.size(); i++)
    {
        if (right[i] + left[i] > max)
            max = right[i] + left[i];
    }
    return max;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> prices{7, 6, 4, 3, 1};
    cout << maxProfit(prices) << endl;
    return 0;
}