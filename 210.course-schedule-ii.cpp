#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
bool checkCircle(unordered_map<int, vector<int>> &adj, vector<int> &color, vector<int> &order, int x)
{
    color[x] = 1;

    for (int i : adj[x])
    {
        if (color[i] == 0)
        {
            if (checkCircle(adj, color, order, i))
                return 1;
        }
        else if (color[i] == 1)
            return 1;
    }

    color[x] = 2;
    order.push_back(x);
    return 0;
}
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> order, color(numCourses, 0);
    unordered_map<int, vector<int>> adj;

    for (auto &pre : prerequisites)
    {
        adj[pre[1]].push_back(pre[0]);
    }

    for (int i = 0; i < numCourses; i++)
    {
        if (color[i] == 0)
        {
            if (checkCircle(adj, color, order, i))
                return vector<int>();
        }
    }

    reverse(order.begin(), order.end());
    return order;
}
int main()
{
    vector<vector<int>> prerequisites = {{1, 0}};
    int numCourses = 2;
    vector<int> res = findOrder(numCourses, prerequisites);
    for (auto i : res)
        cout << i << ' ';
    cout << endl;
    return 0;
}