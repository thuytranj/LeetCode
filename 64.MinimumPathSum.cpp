#include <iostream>
#include <vector>
using namespace std;

// Runtime 5 ms. Beats 72.45% of users with C++
// Memory 12.66 MB. Beats 12.27% of users with C++

int minPathSum(vector<vector<int>> &grid)
{
    vector<vector<int>> res(grid.size(), vector<int>(grid[0].size(), 0));
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (i >= 1 && j >= 1)
            {
                res[i][j] = min(res[i - 1][j], res[i][j - 1]) + grid[i][j];
            }
            else if (i >= 1)
            {
                res[i][j] = res[i - 1][j] + grid[i][j];
            }
            else
            {
                if (j == 0)
                    res[i][j] = grid[i][j];
                else
                    res[i][j] = res[i][j - 1] + grid[i][j];
            }
        }
    }
    return res[grid.size() - 1][grid[0].size() - 1];
}
int main()
{
    vector<vector<int>> grid{{1, 2, 3}, {4, 5, 6}};
    cout << minPathSum(grid) << endl;
    return 0;
}