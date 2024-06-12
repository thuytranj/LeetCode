#include <iostream>
#include <vector>
#include <string>
using namespace std;
void solve (vector<vector<char> > &board, string word, string &tmp, bool &res, int row, int col, vector<vector<bool> >&t) {
    if (word==tmp) {
        res=1;
        return;
    }
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || t[row][col] || board[row][col] != word[tmp.size()])
    {
        return;
    }
    tmp += board[row][col];
    t[row][col]=1;
    solve(board, word, tmp, res, row, col - 1, t);
    solve(board, word, tmp, res,row, col + 1, t);
    solve(board, word, tmp, res, row - 1, col, t);
    solve(board, word, tmp, res, row + 1, col, t);
    tmp.pop_back();
    t[row][col]=0;
}
bool exist(vector<vector<char> > &board, string word)
{
    bool res = 0;
    vector<vector<bool> > t(board.size(), vector<bool>(board[0].size(), 0));
    for (int i=0;i<board.size();i++) {
        for (int j=0;j<board[i].size();j++) {
            string tmp;
            solve(board, word, tmp, res, i, j, t);
            if (res) return 1;
        }
    }
    return 0;
}
int main () {
    int row, col;
    cin >> row >> col;
    vector<vector<char> > board;
    board.resize(row);
    for (int i=0;i<row;i++) {
        board[i].resize(col);
        for (int j = 0; j < col; j++)
        {
            cin >> board[i][j];
        }
    }
    string word;
    cin.ignore();
    getline(cin, word);
    if (exist(board, word)) cout<<1<<endl;
    else cout<<0<<endl;
    return 0;
}