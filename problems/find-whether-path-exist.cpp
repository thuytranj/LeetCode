#include <iostream>
#include <vector>
#include <queue>
using namespace std;

pair<int, int> findSource (vector<vector<int>> &grid) {
    int n = grid.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}
bool is_Possible(vector<vector<int>> &grid)
{
    int n = grid.size();

    vector<vector<bool>> vis(n, vector<bool>(n, 0));
    vector<pair<int, int>> dir{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    pair<int, int> source = findSource(grid);
    queue<pair<int, int>> q;

    q.push(source);
    vis[source.first][source.second] = true;

    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        if (grid[u.first][u.second] == 2) {
            return true;
        }

        for (auto i:dir) {
            int newR = u.first + i.first;
            int newC = u.second + i.second;

            if (newR >= 0 && newR < n && newC >= 0 && newC < n && grid[newR][newC]!= 0 &&!vis[newR][newC]) {
                q.push({newR, newC});
                vis[newR][newC] = true;
            }
        }
    }
    return 0;
}
int main () {
    vector<vector<int>> grid = {{1, 3},
                                {3, 2}};
    if (is_Possible(grid))
        cout << 1 << endl;
    else cout<<0<<endl;
    return 0;
}