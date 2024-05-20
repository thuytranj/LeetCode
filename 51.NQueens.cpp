#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool isValid (vector<int> cur) {
    int rowId = cur.size() - 1;
    for (int i = 0;i<rowId;i++) {
        int diff=abs(cur[i]-cur[rowId]);
        if (diff==0 || diff==rowId-i)
            return 0;
    }
    return 1;
}
void solve(int row, int n, vector<int> &cur, vector<vector<int> > &res)
{
    if (row == n)
    {
        res.push_back(cur);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        cur.push_back(i);
        if (isValid (cur)) solve(row + 1, n, cur, res);
        cur.pop_back();
    }
}
vector<vector<string> > solveNQueens(int n)
{
    vector<int> cur;
    vector<vector<int> > tmp;
    solve(0, n, cur, tmp);
    vector<vector<string> > res;
    for (int i = 0; i < tmp.size();i++) {
        string s(n, '.');
        vector<string> t(n, s);
        for (int j = 0; j < tmp[i].size();j++) {
            t[j][tmp[i][j]] = 'Q';
        }
        res.push_back(t);
    }
    return res;
}
int main (){
    int n;
    cin >> n;
    vector<vector<string> > res = solveNQueens(n);
    for (int i = 0; i < res.size(); i++){
        for (int j = 0;j < n; j++) {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}