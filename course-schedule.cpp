#include <iostream>
#include <vector>
#include <stack>
using namespace std;
bool topo(vector<vector<int>> &adj, vector<int> &color, stack<int> &res, int x)
{
    color[x] = 1;

    for (int i : adj[x])
    {
        if (color[i] == 0)
        {
            if (!topo(adj, color, res, i))
                return 0;
        }
        else if (color[i] == 1)
            return 0;
    }

    res.push(x);
    color[x] = 2;
    return 1;
}
vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites)
{
    vector<vector<int>> adj(n);
    vector<int> color(n, 0), result;
    stack<int> res;

    for (int i = 0; i < prerequisites.size(); i++)
    {
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }

    for (int i = 0; i < n; i++)
    {
        if (color[i] == 0)
        {
            if (!topo(adj, color, res, i))
                return {};
        }
    }

    while (!res.empty())
    {
        result.push_back(res.top());
        res.pop();
    }

    return result;
}
int main()
{
    vector<vector<int>> prerequisites = {{1, 0},
                                         {2, 0},
                                         {3, 1},
                                         {3, 2}};
    vector<int> res = findOrder(4, 4, prerequisites);

    if (res.size() == 0)
        cout << "No prerequisites\n";
    else
    {
        for (int i : res)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}