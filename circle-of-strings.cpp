#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void dfs(unordered_map<char, vector<char>> &adj, vector<int> &vis, int x)
{
    vis[x] = 1;

    for (auto i : adj[x + 'a'])
    {
        if (!vis[i - 'a'])
            dfs(adj, vis, i - 'a');
    }
}
int isCircle(vector<string> &arr)
{
    vector<int> in(26, 0);
    vector<int> out(26, 0);
    unordered_map<char, vector<char>> adj;

    for (auto &s : arr)
    {
        in[s[0] - 'a']++;
        out[s.back() - 'a']++;
        adj[s[0]].push_back(s.back());
    }

    for (int i = 0; i < 26; i++)
    {
        if (in[i] != out[i])
            return 0;
    }

    vector<int> vis(26, 0);
    dfs(adj, vis, arr[0][0] - 'a');

    for (int i = 0; i < 26; i++)
    {
        if (in[i] && !vis[i])
            return 0;
    }

    return 1;
}
int main()
{
    vector<string> arr = {"ab", "bc", "cd", "da"};
    cout << (isCircle(arr) ? "Yes" : "No") << endl;

    return 0;
}