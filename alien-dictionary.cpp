#include <iostream>
#include <vector>
#include <string>
using namespace std;
void topoSort(vector<vector<int>> adj, vector<bool> &vis, string &res, int x)
{
    vis[x] = 1;

    for (auto i : adj[x])
    {
        if (!vis[i])
            topoSort(adj, vis, res, i);
    }

    res.push_back('a' + x);
}
int compare(string a, string b)
{
    int i = 0;
    while (i < a.size() && i < b.size() && a[i] == b[i])
        i++;
    return i;
}
string findOrder(string dict[], int n, int k)
{
    vector<vector<int>> adj(k);
    vector<bool> vis(k, 0);
    string res;

    for (int i = 0; i < n - 1; i++)
    {
        int x = compare(dict[i], dict[i + 1]);
        if (x < dict[i].size() && x < dict[i + 1].size())
            adj[dict[i][x] - 'a'].push_back(dict[i + 1][x] - 'a');
    }

    for (int i = 0; i < k; i++)
    {
        if (!vis[i])
            topoSort(adj, vis, res, i);
    }
    reverse(res.begin(), res.end());
    if (res.size() == k)
        return res;
    return string();
}
int main()
{
    string dict[] = {"caa", "aaa", "aab"};
    int n = 3, k = 3;
    cout << findOrder(dict, n, k) << endl;
    return 0;
}