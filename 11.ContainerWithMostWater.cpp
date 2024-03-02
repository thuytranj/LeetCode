#include <iostream>
#include <vector>
using namespace std;

// Runtime 78 ms. Beats 12.51% of users with C++
// Memory 59.31 MB. Beats 86.37% of users with C++

int maxArea(vector<int> &height)
{
    int i = 0, j = height.size() - 1;
    int max = 0;
    while (i < j)
    {
        int shorter_line = min(height[i], height[j]);
        if (shorter_line * (j - i) > max)
            max = shorter_line * (j - i);
        if (height[i] < height[j])
            i++;
        else
            j--;
    }
    return max;
}
int main()
{
    vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height) << endl;
    return 0;
}