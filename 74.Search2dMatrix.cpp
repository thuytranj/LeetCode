#include <iostream>
#include <vector>
using namespace std;

// Runtime 3 ms. Beats 63.98% of users with C++
// Memory 12.18 MB. Beats 7.25% of users with C++

int findRow(vector<vector<int>> matrix, int target)
{
    int l = 0, r = matrix.size() - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (matrix[m][0] == target || (matrix[m][0] < target && (m == matrix.size() - 1 || matrix[m + 1][0] > target)))
            return m;
        else
        {
            if (matrix[m][0] < target)
                l = m + 1;
            else
                r = m - 1;
        }
    }
    return -1;
}
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = findRow(matrix, target);
    if (row == -1)
        return false;
    if (matrix[row][0] == target)
        return true;
    else
    {
        int l = 1, r = matrix[row].size() - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (matrix[row][m] == target)
                return true;
            else
            {
                if (matrix[row][m] < target)
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 60}};
    int target = 70;
    if (searchMatrix (matrix, target))
        cout << "yes\n";
    else
        cout << "no\n";
    return 0;
}