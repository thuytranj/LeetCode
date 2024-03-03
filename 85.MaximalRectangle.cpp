#include <iostream>
#include <vector>
using namespace std;

// Runtime 293 ms. Beats 5.03% of users with C++
// Memory 155.26 MB. Beats 5.09% of users with C++

void findRightLeft(vector<int> heights, int n, int index, int &right, int &left)
{
    left = 0;
    right = n - 1;
    for (int i = index - 1; i >= 0; i--)
    {
        if (heights[i] < heights[index])
        {
            left = i + 1;
            break;
        }
    }
    for (int i = index + 1; i < n; i++)
    {
        if (heights[i] < heights[index])
        {
            right = i - 1;
            break;
        }
    }
}
int largestRectangleArea(vector<int> &heights)
{
    int maxArea = 0, left, right, area;
    for (int i = 0; i < heights.size(); i++)
    {
        findRightLeft(heights, heights.size(), i, right, left);
        area = heights[i] * (right - left + 1);
        if (area > maxArea)
            maxArea = area;
    }
    return maxArea;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    int max = 0;
    vector<int> count(matrix[0].size(), 0);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == '1')
                count[j]++;
            else
                count[j] = 0;
        }
        int area = largestRectangleArea(count);
        if (area > max)
            max = area;
    }
    return max;
}
int main()
{
    vector<vector<char>> matrix{{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    cout << maximalRectangle (matrix)<<endl;
     return 0;
}