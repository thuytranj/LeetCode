#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxArea(vector<int> nums)
{
    int res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int heightMin = nums[i];
        for (int j = i; j < nums.size(); j++)
        {
            heightMin = min(heightMin, nums[j]);
            if (j - i + 1 <= heightMin)
                res = max(res, (int)pow(j - i + 1, 2));
            else
                break;
        }
        if (nums[i])
            res = max(res, 1);
    }
    return res;
}
int maximalSquare(vector<vector<char> > &matrix)
{
    int Max = 0;
    vector<int> nums(matrix[0].size(), 0);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == '1')
                nums[j] += 1;
            else
                nums[j] = 0;
        }
        Max = max(Max, maxArea(nums));
    }
    return Max;
}
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<char> > matrix;
    matrix.resize(m);
    for (int i = 0; i < m; i++)
    {
        matrix[i].resize(n);
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << maximalSquare(matrix) << endl;
    return 0;
}