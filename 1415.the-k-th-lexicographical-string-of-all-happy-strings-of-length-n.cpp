#include <iostream>
#include <string>
#include <vector>
using namespace std;
void solve(int n, int k, string &res, vector<string> &cur, string &tmp)
{
    if (tmp.size() > 1 && tmp.back() == tmp[tmp.size() - 2])
        return;
    if (tmp.size() == n)
    {
        cur.push_back(tmp);
        if (cur.size() == k)
        {
            res = cur.back();
            return;
        }
        return;
    }
    for (char i = 'a'; i <= 'c'; i++)
    {
        tmp += i;
        solve(n, k, res, cur, tmp);
        if (!res.empty())
            return;
        tmp.pop_back();
    }
}
string getHappyString(int n, int k)
{
    string tmp, res="";
    vector<string> cur;
    solve(n, k, res, cur, tmp);
    return res;
}
int main(int argc, char *argv[])
{
    int n, k;
    cin >> n >> k;
    cout << getHappyString(n, k) << endl;
    return 0;
}
