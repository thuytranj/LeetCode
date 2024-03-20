#include <iostream>
#include <vector>
using namespace std;
// Runtime 2 ms. Beats 88.88% of users with C++
// Memory 10.92 MB. Beats 86.87% of users with C+
int minimumTotal(vector<vector<int>> &triangle)
{
    for (int i = 1; i < triangle.size(); i++)
    {
        triangle[i][0] += triangle[i - 1][0];
        for (int j = 1; j < triangle[i].size() - 1; j++)
        {
            triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
        }
        triangle[i][triangle[i].size() - 1] += triangle[i - 1][triangle[i - 1].size() - 1];
    }
    return *min_element(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end());
}
int main()
{
    vector<vector<int>> triangle = {{2}};
    cout << minimumTotal(triangle) << endl;
    return 0;
}
int maxProfit(vector<int> &prices)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int buy = prices[0];
    int profit = 0;
    for (int x : prices)
    {
        if (x < buy)
            buy = x;
        if (profit < x - buy)
            profit = x - buy;
    }
    return profit;
}