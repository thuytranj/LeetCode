#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
void check (vector<vector<char> >&board, string str, string &cur, int row, int col, set<pair<int, int> > &index, bool &res) {
    if (cur==str) {
        res = 1;
        return;
    }
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || (cur.size() > 0 && cur[cur.size() - 1] != str[cur.size() - 1]) || index.find(make_pair(row, col)) != index.end() || cur.size()>str.size())
        return;
    cur += board[row][col];
    index.insert (make_pair (row, col));

    check(board, str, cur, row, col + 1, index, res);
    check(board, str, cur, row, col - 1, index, res);
    check(board, str, cur, row + 1, col, index, res);
    check(board, str, cur, row - 1, col, index, res);
    
    cur.erase(cur.begin() + cur.size() - 1);
    index.erase (make_pair (row, col));
}
vector<string> findWords(vector<vector<char> > &board, vector<string> &words)
{
    vector<string> res;
    
    for (int i=0;i<board.size();i++) {
        for (int j=0;j<board[0].size();j++) {
            for (int k=0;k<words.size();k++) {
                if (board[i][j]==words[k][0]) {
                    bool tmp=0;
                    string cur = "";
                    set<pair<int, int> > index;
                    check(board, words[k], cur, i, j, index, tmp);
                    if (tmp) {
                        res.push_back(words[k]);
                        words.erase(words.begin() + k);
                        k--;
                    }
                }
            }
        }
    }
    return res;
}
int main () {
    int row, col;
    cin>>row>>col;
    vector<vector<char> > board(row);
    for (int i=0;i<row;i++) {
        board[i].resize(col);
        for (int j=0;j<col;j++) {
            cin >> board[i][j];
        }
    }
    
    int n;
    cin >> n;
    cin.ignore();
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        getline(cin, words[i]);
    }

    vector<string> res = findWords(board, words);
    for (int i=0;i<res.size();i++) {
        cout<<res[i]<<endl;
    }
    return 0;
}