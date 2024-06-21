#include <iostream>
#include <vector>
using namespace std;

void solve(vector<vector<int> > &grid, vector<vector<bool> > &check, vector<pair<int, int> > &directions,  int row, int col, int &res, int sum)
{
    res = max(res, sum);
    for (int i=0;i<directions.size();i++) {
        int r=row+directions[i].first;
        int c=col+directions[i].second;

        if (r>=0 && r<grid.size() && c<grid[0].size() && c>=0 && check[r][c]==0 && grid[r][c]!=0) {
            check[r][c]=1;
            solve(grid, check, directions, r, c, res, sum+grid[r][c]);
            check[r][c]=0;
        }
    }
}
int getMaximumGold(vector<vector<int> > &grid)
{
    int res = 0;
    vector<vector<bool> > check(grid.size(), vector<bool>(grid[0].size(), 0));
    vector<pair<int, int> > directions;
    directions.push_back(make_pair(0, -1));
    directions.push_back(make_pair(0, 1));
    directions.push_back(make_pair(-1, 0));
    directions.push_back(make_pair(1, 0));

    for (int i=0;i<grid.size();i++) {
        for (int j =0; j<grid[0].size();j++) {
            if (grid[i][j]!= 0) {
                check[i][j]=1;
                solve(grid, check, directions, i, j, res, grid[i][j]);
                check[i][j]=0;
            }
        }
    }
    return res;
}
int main () {
    int m, n;
    cin>>m>>n;
    vector<vector<int> > grid(m);
    for (int i = 0; i < m; i++)
    {
        grid[i].resize(n);
        for (int j=0;j<n;j++) {
            cin >> grid[i][j];
        }
    }
    cout<<getMaximumGold (grid)<<endl;
    return 0;
}