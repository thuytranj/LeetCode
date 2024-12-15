#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
{
    int n = profits.size();
    vector<pair<int, int>> projects;
    for (int i = 0; i < n; i++)
    {
        projects.push_back({capital[i], profits[i]});
    }

    sort(projects.begin(), projects.end());
    int i = 0;
    priority_queue<int, vector<int>> pq;
    while (k--)
    {
        while (i < n && projects[i].first <= w)
        {
            pq.push(projects[i].second);
            i++;
        }
        if (pq.empty())
            break;
        w += pq.top();
        pq.pop();
    }
    return w;
}
int main()
{
    int k = 3, w = 0;
    vector<int> profits = {1, 2, 3}, capital = {0, 1, 2};
    cout << findMaximizedCapital(k, w, profits, capital) << endl; // Output: 4
    return 0;
}