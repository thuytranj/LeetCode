#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
};
int bfs (unordered_map <int, pair<int, vector<int>>> adj, int id) {
    int sum=0;
    queue<int> q;
    q.push(id);

    while (!q.empty()) {
        auto tmp = q.front();
        q.pop();
        sum+=adj[tmp].first;

        for (auto i:adj[tmp].second) {
            q.push(i);
        }
    }

    return sum;
}
int getImportance(vector<Employee *> employees, int id)
{
    unordered_map<int, pair<int, vector<int>>> adj;
    for (Employee* e : employees) {
        adj[e->id] = {e->importance, e->subordinates};
    }
    return bfs(adj, id);
}
int main () {
    return 0;
}