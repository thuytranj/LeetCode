#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;
int kthSmallest(vector<vector<int>> &mat, int k)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    set<pair<int, int>> vis;
    q.push({mat[0][0], {0, 0}});
    vis.insert({0, 0});
    int cnt = 0, res = mat[0][0];

    while (cnt != k)
    {
        pair<int, pair<int, int>> top = q.top();
        q.pop();

        res = top.first;
        cnt++;
        int x = top.second.first;
        int y = top.second.second;

        if (y + 1 < mat[0].size() && vis.find({x, y + 1}) == vis.end())
        {
            q.push({mat[x][y + 1], {x, y + 1}});
            vis.insert({x, y + 1});
        }
        if (x + 1 < mat.size() && vis.find({x + 1, y}) == vis.end())
        {
            q.push({mat[x + 1][y], {x + 1, y}});
            vis.insert({x + 1, y});
        }
    }
    return res;
}
int main()
{
    vector<vector<int>> mat{{1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9, 4}};
    cout << kthSmallest(mat, 7) << endl;
    return 0;
}