#include <iostream>
#include <string>
#include <vector>
using namespace std;
int count (const string& s1, const string& s2) {
    int cnt = 0;
    for (int i=0;i<s1.size();i++) {
        if (s1[i] != s2[i])
            cnt++;
    }
    return cnt;
}
void solve (const string& beginWord, const string& endWord, vector<string> wordList, vector<vector<string>> &res, vector<string> &cur){
 
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    vector<vector<string> > res;
    if (find(wordList.begin(), wordList.end(), endWord)==wordList.end()) return res;
    vector<string> cur;
    solve(beginWord, endWord, res, cur);
    return res;
}
int main () {
    string beginWord, endWord;
    getline(cin, beginWord);
    getline (cin, endWord);
    int n;
    cin>>n;
    vector<string> wordList(n);
    for (int i=0;i<n;i++) {
        getline (cin, wordList[i]);
    }
    vector<vector<string> > res=findLadders(beginWord, endWord, wordList);
    for (int i=0;i<res.size();i++) {
        for (int j=0;j<res[i].size();j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}