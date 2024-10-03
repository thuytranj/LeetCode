#include <iostream>
#include <vector>
using namespace std;
void help(vector<int> &toppingCosts, int target, int &res, int &sum, int pos)
{
    if (pos == toppingCosts.size())
    {
        if (abs(target - sum) < abs(target - res))
            res = sum;
        else if (abs(target-sum)==abs (target-res)) {
            res = min(res, sum);
        }
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        sum += i * toppingCosts[pos];
        help(toppingCosts, target, res, sum, pos + 1);
        if (sum < 0)
            return;
        sum -= i * toppingCosts[pos];
    }
}
int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts, int target)
{
    int res = INT_MAX;
    for (int i = 0; i < baseCosts.size(); i++)
    {
        if (baseCosts[i] == target)
            return target;
        else if (baseCosts[i] < target)
        {
            int cur = INT_MAX, sum = 0;
            help(toppingCosts, target - baseCosts[i], cur, sum, 0);
            if (abs(baseCosts[i] + cur - target) < abs(res - target))
                res = baseCosts[i] + cur;
            else if (abs(baseCosts[i] + cur - target) == abs(res - target))
                res = min(res, baseCosts[i] + cur);
        }
        else
        {
            if (baseCosts[i] - target < abs(target - res))
                res = baseCosts[i];
            else if (baseCosts[i]-target==abs (target-res))
                res = min(res, baseCosts[i]);
        }
    }
    return res;
}
int main()
{
    int n, m, target;
    cin >> n >> m >> target;
    vector<int> baseCosts(n), toppingCosts(m);
    for (int i = 0; i < n; i++)
    {
        cin >> baseCosts[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> toppingCosts[i];
    }
    cout << closestCost(baseCosts, toppingCosts, target) << endl;
    return 0;
}