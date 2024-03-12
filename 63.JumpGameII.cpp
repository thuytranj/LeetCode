#include <iostream>
#include <vector>
using namespace std;
// Runtime 5 ms. Beats 36.75% of users with C++
// Memory 9.9 MB. Beats 85.19% of users with C++

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    for (int i = 0; i < obstacleGrid.size(); i++)
    {
        for (int j = 0; j < obstacleGrid[0].size(); j++)
        {
            if (obstacleGrid[i][j] == 1)
                obstacleGrid[i][j] = 0;
            else
                obstacleGrid[i][j] = 1;
        }
    }
    for (int i = 0; i < obstacleGrid.size(); i++)
    {
        for (int j = 0; j < obstacleGrid[0].size(); j++)
        {
            if (j >= 1 && i >= 1)
            {
                if (obstacleGrid[i][j] != 0)
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
            }
            else if (j >= 1)
            {
                if (obstacleGrid[i][j - 1] == 0)
                    obstacleGrid[i][j] = obstacleGrid[i][j - 1];
            }
            else if (i >= 1)
            {
                if (obstacleGrid[i - 1][j] == 0)
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j];
            }
        }
    }

    return obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
}
int main()
{
    vector<vector<int>> obstacleGrid{{0, 1}, {1, 0}};
    cout << uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}