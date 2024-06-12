#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
int convert (const string& s) {
    int res=0, cnt=0;
    for (int i=s.size()-1;i>=0;i--) {
        res += pow(2, cnt) * (s[i] - '0');
        cnt++;
    }
    return res;
}
void solve (int n, vector<string> &res, unordered_set<string> &seen, string &tmp) {
    if (res.size()==pow(2,n)) return;

    if (seen.find(tmp)==seen.end()){
        res.push_back(tmp);
        seen.insert(tmp);
        
        for (int i=tmp.size()-1;i>=0;i--) {
            if (tmp[i] == '0') {
                tmp[i] = '1';
                solve(n, res, seen, tmp);
                tmp[i] = '0';
            }
            else {
                tmp[i] = '0';
                solve(n, res, seen, tmp);
                tmp[i] = '1';
            }
        }
        seen.erase(tmp);
    }
}
vector<int> grayCode(int n)
{
    vector<string> cur;
    unordered_set <string> seen;
    string tmp(n, '0');
    solve(n, cur, seen, tmp);

    vector<int> res;
    for (int i=0;i<cur.size();i++) {
        cout<<cur[i]<<endl;
        res.push_back(convert(cur[i]));
    }
    return res;
}
// vector<int> grayCode(int n)
// {
//     vector<int> res;
//     int total = 1 << n; // Tổng số mã Gray cho n bit
//     for (int i = 0; i < total; ++i)
//     {
//         res.push_back(i ^ (i >> 1));
//     }
//     return res;
// }
int main () {
    int n;
    cin>>n;
    vector<int> res = grayCode(n);
    for (int i=0;i<res.size();i++) {
        cout << res[i] << ' ';
    }
    cout<<endl;
    return 0;
}