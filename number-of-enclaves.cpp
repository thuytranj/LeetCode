#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs (vector<vector<int>> &grid, vector<vector<bool>> &vis, vector<pair<int, int>> &dir, int x, int y) {
    queue<pair<int,int>> q;
    q.push({x, y});
    vis[x][y]=1;

    while (!q.empty()) {
        int r=q.front().first;
        int c=q.front().second;
        q.pop();

        for (auto i:dir) {
            int newR=r+i.first;
            int newC=c+i.second;

            if (newR>=0 && newR<grid.size() && newC>=0 && newC<grid[0].size() && grid[newR][newC]==1 &&!vis[newR][newC]) {
                q.push({newR, newC});
                vis[newR][newC]=1;
            }
        }
    }
}
int numberOfEnclaves(vector<vector<int>> &grid)
{
    int n=grid.size(), m=grid[0].size();
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    int res=0;

    for (int i=0;i<m;i++) {
        if (grid[0][i]==1 && !vis[0][i]) {
            bfs(grid, vis, dir, 0, i);
        }
        if (grid[n-1][i] == 1 && !vis[n-1][i])
        {
            bfs(grid, vis, dir, n-1, i);
        }
    }

    for (int i=0;i<n;i++) {
        if (grid[i][0] == 1 && !vis[i][0])
        {
            bfs(grid, vis, dir, i, 0);
        }

        if (grid[i][m-1] == 1 && !vis[i][m-1])
        {
            bfs(grid, vis, dir, i, m-1);
        }
    }

    for (int i = 1;i<n-1;i++) {
        for (int j=1;j<m-1;j++) {
            if (grid[i][j] == 1 && !vis[i][j])
                res++;
        }
    }

    return res;
}
int main () {
    vector<vector<int>> grid = {{0, 0, 0, 1},
                                {0, 1, 1, 0},
                                {0, 1, 1, 0},
                                {0, 0, 0, 1},
                                {0, 1, 1, 0}};

    cout<<numberOfEnclaves(grid)<<endl;
    return 0;
}