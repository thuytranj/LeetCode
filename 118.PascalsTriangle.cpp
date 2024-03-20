#include <iostream>
#include <vector>
using namespace std;
// Runtime 0 ms. Beats 100% of users with C++
// Memory 8.02 MB. Beats 18.5% of users with C+
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> res;
    vector<int> cur;
    cur.push_back(1);
    res.push_back(cur);
    if (numRows == 1)
        return res;
    cur.push_back(1);
    res.push_back(cur);
    if (numRows == 2)
        return res;
    for (int i = 2; i < numRows; i++)
    {
        cur.clear();
        cur.push_back(1);
        for (int j = 0; j < res[res.size() - 1].size() - 1; j++)
        {
            cur.push_back(res[res.size() - 1][j] + res[res.size() - 1][j + 1]);
        }
        cur.push_back(1);
        res.push_back(cur);
    }
    return res;
}
int main (){
    int num;
    cin>>num;
    vector<vector<int>> res=generate (num);
    for (int i=0;i<res.size();i++) {
        for (int j=0;j<res[i].size();j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}