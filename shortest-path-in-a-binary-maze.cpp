#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
{
    int n = grid.size(), m = grid[0].size();
    vector<pair<int, int>> directions{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    queue<pair<int, int>> q;
    q.push(source);
    grid[source.first][source.second] = 0;
    int cnt = 0;

    while (!q.empty())
    {
        int s = q.size();
        while (s--)
        {
            if (q.front() == destination)
                return cnt;
            int r = q.front().first;
            int c = q.front().second;

            q.pop();
            for (auto dir : directions)
            {
                int nr = r + dir.first;
                int nc = c + dir.second;
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc])
                {
                    q.push({nr, nc});
                    grid[nr][nc] = 0;
                }
            }
        }
        cnt++;
    }

    return -1;
}
int main()
{
    vector<vector<int>> grid = {{1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 0},
                                {1, 0, 1, 0, 1}};
    pair<int, int> source = {0, 0}, des = {3, 4};
    cout << shortestPath(grid, source, des) << endl;
    return 0;
}