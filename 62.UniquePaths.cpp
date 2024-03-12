#include <iostream>
#include <vector>
using namespace std;
// Runtime 0 ms. Beats 100% of users with C++
// Memory 7.61 MB. Beats 39.53% of users with C++
int uniquePaths(int m, int n)
{
    vector<vector<int>> matrix(m, vector<int>(n, 1));
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            matrix[i][j] = matrix[i][j - 1] + matrix[i - 1][j];
        }
    }
    return matrix[m - 1][n - 1];
}
int main()
{
    int m, n;
    cin>>m>>n;
    cout<<uniquePaths(m, n)<<endl;
    return 0;
}