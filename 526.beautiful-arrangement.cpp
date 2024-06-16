#include <iostream>
#include <vector>
#include <set>
using namespace std;
void solve(int n, set<int> &cur, int x, int &res)
{
    if (cur.size() == n)
    {
        res++;
        return;
    }
    for (int j = 1; j <= n; j++)
    {
        if ((j % (cur.size()+1)== 0 || (cur.size()+1) % j == 0) && cur.find(j) == cur.end())
        {
            cur.insert(j);
            solve(n, cur, j, res);
            cur.erase(j);
        }
    }
}
int countArrangement(int n)
{
    int res = 0;
    set<int> cur;
    solve(n, cur, 1, res);
    return res;
}
int main()
{
    int n;
    cin >> n;
    cout << countArrangement(n) << endl;
    return 0;
}