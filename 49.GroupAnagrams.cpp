#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Runtime 18 ms. Beats 95.68% of users with C++
// Memory 41.48 MB. Beats 97.59% of users with C++

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mymap;
    string temp;
    for (int i = 0; i < strs.size(); i++)
    {
        temp = strs[i];
        sort(strs[i].begin(), strs[i].end());
        mymap[strs[i]].push_back(temp);
    }
    vector<vector<string>> result;
    for (auto it = mymap.begin(); it != mymap.end(); it++)
    {
        result.push_back(it->second);
    }
    return result;
}
void output(vector<vector<string>> res) {
    for (int i=0;i<res.size();i++){
        for (int j = 0; j < res[i].size();j++){
            cout << res[i][j] << ' ';
        }
        cout<<endl;
    }
}
int main()
{
    vector<string> s{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = groupAnagrams(s);
    output(res);
    return 0;
}