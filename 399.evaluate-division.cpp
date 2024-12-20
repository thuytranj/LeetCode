#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

double bfs(unordered_map<string, unordered_map<string, double>> &graph, string start, string end)
{
    if (graph.find(end) == graph.end() || graph.find(start) == graph.end())
        return -1.0;
    if (start == end)
        return 1.0;

    queue<pair<string, double>> q;
    unordered_map<string, bool> visited;
    q.push({start, 1.0});
    visited[start] = true;

    while (!q.empty())
    {
        pair<string, double> node = q.front();
        q.pop();
        string u = node.first;
        double val = node.second;
        if (u == end)
            return val;

        for (auto &neighbor : graph[u])
        {
            string v = neighbor.first;
            double weight = neighbor.second;
            if (visited.find(v) == visited.end())
            {
                visited[v] = true;
                q.push({v, val * weight});
            }
        }
    }

    return -1.0;
}

vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
    unordered_map<string, unordered_map<string, double>> graph;
    for (int i = 0; i < equations.size(); i++)
    {
        string u = equations[i][0];
        string v = equations[i][1];
        double val = values[i];
        graph[u][v] = val;
        graph[v][u] = 1 / val;
    }

    vector<double> res;
    for (int i = 0; i < queries.size(); i++)
    {
        string u = queries[i][0];
        string v = queries[i][1];

        res.push_back(bfs(graph, u, v));
    }

    return res;
}

int main()
{
    vector<vector<string>> equations = {{"a", "b"}};
    vector<double> values = {0.5};
    vector<vector<string>> queries = {{"a", "b"}, {"b", "a"}, {"a", "c"}, {"x", "y"}};

    vector<double> res = calcEquation(equations, values, queries);
    for (auto i : res)
        cout << i << ' ';
    cout << endl;
    return 0;
}