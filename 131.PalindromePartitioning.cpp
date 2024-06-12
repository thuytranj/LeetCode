#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool isValid(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start] != s[end])
            return 0;
        start++;
        end--;
    }
    return 1;
}
void solve(string s, int start, vector<string> &current, vector<vector<string> > &res)
{
    if (start == s.size())
    {
        res.push_back(current);
        return;
    }
    for (int i = start; i < s.size(); i++)
    {
        if (isValid(s, start, i))
        {
            current.push_back(s.substr(start, i - start + 1));
            solve(s, i + 1, current, res);
            current.pop_back();
        }
    }
}
vector<vector<string> > partition(string s)
{
    vector<vector<string> > res;
    vector<string> current;
    solve(s, 0, current, res);
    return res;
}
int main (){
    string s;
    getline(cin, s);
    vector<vector<string> > res = partition(s);
    for (int i = 0; i < res.size(); i++){
        for (int j = 0;j<res[i].size();j++) {
            cout<<res[i][j]<<" ";
        }
        cout << endl;
    }
    return 0;
}