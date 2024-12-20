#include <iostream>
#include <vector>
using namespace std;

void dfs(int cur, int n, vector<int> &res)
{
    if (cur > n)
        return;
    res.push_back(cur);

    for (int i = 0; i < 10; i++)
    {
        dfs(10 * cur + i, n, res);
    }
}
vector<int> lexicalOrder(int n)
{
    vector<int> res;
    for (int i = 1; i < 10; i++)
    {
        dfs(i, n, res);
    }

    return res;
}
int main()
{
    int n = 13;
    vector<int> res = lexicalOrder(n);
    for (auto i : res)
        cout << i << ' ';
    cout << endl;
    return 0;
}