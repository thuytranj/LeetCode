#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool checkCircle(unordered_map<int, vector<int>> &adj, vector<int> &color, int x)
{
    color[x] = 1;
    for (auto i : adj[x])
    {
        if (color[i] == 0)
        {
            if (checkCircle(adj, color, i))
                return 1;
        }
        else if (color[i] == 1)
            return 1;
    }
    color[x] = 2;
    return 0;
}
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> color(numCourses, 0);

    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < prerequisites.size(); i++)
    {
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }

    for (int i = 0; i < numCourses; i++)
    {
        if (color[i] == 0)
        {
            if (checkCircle(adj, color, i))
                return 0;
        }
    }

    return 1;
}
int main()
{
    vector<vector<int>> prerequisites{{1, 0}};
    int numCourses = 2;
    if (canFinish(numCourses, prerequisites))
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}