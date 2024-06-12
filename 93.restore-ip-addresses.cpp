#include <iostream>
#include <string>
#include <vector>
using namespace std;
int count (string s) {
    int cnt=0;
    for (int i=0;i<s.size();i++) {
        if (s[i]=='.')
            cnt++;
    }
    return cnt;
}
void solve (string s, vector<string>& res, string &tmp, int pos) {
    int t2 = count(tmp);
    if (t2 == 3)
    {
        int num=0, j=tmp.size()-1, cnt=0;
        while (j>=0 && tmp[j]!='.') {
            num += pow(10, cnt)*(tmp[j] - '0');
            cnt++;
            j--;
        }
        if (num>255 || (tmp[pos+t2]=='0' && cnt>1)) return;
        res.push_back(tmp);
        return;
    }
    for (int i=1;i<=3;i++) {
        if (pos+i>=s.size()) return;
        string cur = s.substr(pos, i);
        int t = stoi(cur);
        if (t>255 || (cur[0]=='0' && cur.size()>1)) return;
        tmp.insert(pos+i + t2, ".");
        solve(s, res, tmp, pos + i);
        tmp.erase(pos+i+t2, 1);
    }
}
vector<string> restoreIpAddresses(string s)
{
    vector<string> res;
    if (s.size()<4 || s.size()>12) return res;
    string tmp=s;
    solve(s, res, tmp, 0);
    return res;
}
int main () {
    string s;
    getline(cin, s);
    vector<string> res=restoreIpAddresses(s);
    for (int i=0;i<res.size();i++) {
        cout<<res[i]<<endl;
    }
    return 0;
}