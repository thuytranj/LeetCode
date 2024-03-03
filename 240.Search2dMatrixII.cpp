#include <iostream>
#include <vector>
using namespace std;

// Runtime 97 ms. Beats 24.02% of users with C++
// Memory 18.45 MB. Beats 8.32% of users with C++

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix[i][0] == target || matrix[i][matrix[0].size() - 1] == target)
            return true;
        if (matrix[i][0] < target && matrix[i][matrix[0].size() - 1] > target)
        {
            if (binary_search(matrix[i].begin(), matrix[i].end(), target))
                return true;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> matrix{{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target =5;
    if (searchMatrix (matrix, target))
        cout << "yes\n";
    else
        cout << "no\n";
    return 0;
}