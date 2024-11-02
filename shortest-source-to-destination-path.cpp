#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y)
{
    vector<vector<bool>> vis (N, vector<bool> (M, 0));
    vector<pair<int, int>> index = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    queue<pair<int, int>> q;
    q.push({0, 0});
    int cnt=0;
    vis[0][0]=1;

    while (!q.empty()) {
        int s = q.size();
        cnt++;
        for (int i = 0; i < s; i++)
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (auto j:index) {
                int newR = r + j.first;
                int newC=c + j.second;

                if (newR>=0 && newR<N && newC>=0 && newC<M && A[newR][newC] && !vis[newR][newC]) {
                    if (newR==X && newC==Y) return cnt;
                    vis[newR][newC]=1;
                    q.push({newR, newC});
                }
            }
        }
    }

    return -1;
}
int main () {
    vector<vector<int>> A = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {0, 1, 1, 1}};

    int N=3, M=4, X=2, Y=3;
    cout<<shortestDistance (N, M, A, X, Y)<<endl;
    return 0;
}