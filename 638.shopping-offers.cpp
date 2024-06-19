#include <iostream>
#include <vector>
using namespace std;

int isValidSum(vector<int> &needs, vector<int> &sum, int &pos)
{
    for (int i = 0; i < min(sum.size(), needs.size()); i++)
    {
        if (sum[i] > needs[i])
            return 0;
    }
    return 1;
}
void solve(vector<int> &price, vector<vector<int> > &special, vector<int> &needs, vector<int> &sum, int pos, int &res)
{
    int check = isValidSum(needs, sum, pos);
    if (check == 0)
        return;
    int tmp = 0;
    for (int i = 0; i < min(needs.size(), sum.size()); i++)
    {
        if (needs[i] - sum[i] > 0)
            tmp += price[i] * (needs[i] - sum[i]);
    }
    res = min(res, tmp + sum[sum.size() - 1]);
    for (int i = pos; i < special.size(); i++)
    {
        for (int j = 0; j < sum.size(); j++)
        {
            sum[j] += special[i][j];
        }

        solve(price, special, needs, sum, i, res);
        for (int j = 0; j < sum.size(); j++)
        {
            sum[j] -= special[i][j];
        }
    }
}

int shoppingOffers(vector<int> &price, vector<vector<int> > &special, vector<int> &needs)
{
    int res = 0;
    for (int i = 0; i < price.size(); i++)
    {
        res += needs[i] * price[i];
    }
    vector<int> sum(needs.size() + 1, 0);
    solve(price, special, needs, sum, 0, res);
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> price(n);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    int m;
    cin >> m;
    vector<vector<int> > special(m);
    for (int i = 0; i < m; i++)
    {
        special[i].resize(n + 1);
        for (int j = 0; j <= n; j++)
        {
            cin >> special[i][j];
        }
    }
    vector<int> needs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> needs[i];
    }
    cout << shoppingOffers(price, special, needs) << endl;
    return 0;
}