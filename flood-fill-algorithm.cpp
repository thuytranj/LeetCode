#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    vector<pair<int, int>> pos{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    vector<vector<bool>> vis(image.size(), vector<bool>(image[0].size(), 0));
    vis[sr][sc] = 1;
    queue<pair<int, int>> q;
    q.push({sr, sc});
    int oldColor = image[sr][sc];
    image[sr][sc] = newColor;

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (auto i : pos)
        {
            int newR = r + i.first;
            int newC = c + i.second;

            if (newR >= 0 && newR < image.size() && newC >= 0 && newC < image[0].size() && image[newR][newC] == oldColor && !vis[newR][newC])
            {
                q.push({newR, newC});
                vis[newR][newC] = 1;
                image[newR][newC] = newColor;
            }
        }
    }

    return image;
}
int main()
{
    return 0;
}