#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <stack>
using namespace std;
vector<string> findItinerary(vector<vector<string>> &tickets)
{
    unordered_map<string, multiset<string>> adj;

    for (int i = 0; i < tickets.size(); i++)
    {
        adj[tickets[i][0]].insert(tickets[i][1]);
    }

    stack<string> s;
    vector<string> ec;
    s.push("JFK");

    while (!s.empty())
    {
        string u = s.top();

        if (!adj[u].empty())
        {
            auto tmp = adj[u].begin();
            s.push(*tmp);
            adj[u].erase(tmp);
        }
        else
        {
            s.pop();
            ec.push_back(u);
        }
    }
    reverse(ec.begin(), ec.end());

    return ec;
}
int main()
{
    vector<vector<string>> tickets = {{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};
    vector<string> res = findItinerary(tickets);
    for (auto i : res)
        cout << i << ' ';
    cout << endl;
    return 0;
}