#include <iostream>
#include <vector>
using namespace std;

// Time Limit Exceeded
// 87 / 98 testcases passed

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
int main()
{
    vector<int> height{2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea (height)<<endl;
    return 0;
}