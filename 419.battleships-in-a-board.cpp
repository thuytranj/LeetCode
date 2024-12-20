#include <iostream>
#include <vector>
using namespace std;
void dfs (vector<vector<char>> &board, vector<vector<int>> &vis, vector<pair<int, int>> & dir, int x, int y) {
    vis[x][y] = 1;

    for (auto i:dir) {
        int nr=x + i.first;
        int nc=y + i.second;

        if (nr>=0 && nr<board.size() && nc>=0 && nc<board[0].size() && board[nr][nc]=='X' && !vis[nr][nc]) {
            dfs(board, vis, dir, nr, nc);
        }
    }
}
int countBattleships(vector<vector<char>> &board)
{
    int cnt=0;
    vector<vector<int>> vis(board.size(), vector<int>(board[0].size(), 0));
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for (int i=0;i<board.size();i++) {
        for (int j=0;j<board[0].size();j++) {
            if (board[i][j]=='X' && !vis[i][j]) {
                cnt++;
                dfs(board, vis, dir, i, j);
            }
        }
    }

    return cnt;
}
int main () {
    vector<vector<char>> board = {{'X', '.', '.', 'X'}, {'.', '.', '.', 'X'}, {'.', '.', '.', 'X'}};
    cout<<countBattleships(board)<<endl;
    return 0;
}