#include <iostream>
#include <vector>
#include <set>
using namespace std;
int trap(vector<int> &height)
{
    int maxLeft = 0, maxRight = 0;
    // water over any block = min(maxLeftWall, maxRightWall) - height[i]
    int l = 0, r = height.size() - 1, water, ans = 0;
    while (l <= r)
    {
        // choose the block to calc. we choose the min one
        if (maxLeft <= maxRight)
        {
            water = max(maxLeft - height[l], 0);
            ans += water;
            maxLeft = max(height[l], maxLeft);
            l++;
        }
        else
        {
            water = max(maxRight - height[r], 0);
            ans += water;
            maxRight = max(height[r], maxRight);
            r--;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    cout << trap(height) << endl;
    return 0;
}