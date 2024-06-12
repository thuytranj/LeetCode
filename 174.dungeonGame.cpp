#include <iostream>
#include <vector>
using namespace std;
int calculateMinimumHP(vector<vector<int> > &dungeon)
{
    vector<vector<int> > res = dungeon;
    for (int i = 1;i<dungeon[0].size();i++) {
        res[0][i] = res[0][i - 1] + dungeon[0][i];
    }
    for (int i = 1;i<dungeon.size();i++) {
        res[i][0]=res[i-1][0]+dungeon[i][0];
    }
        for (int i = 1; i < dungeon.size(); i++)
        {
            for (int j = 1; j < dungeon.size(); j++)
            {
                res[i][j] = max(res[i][j - 1], res[i - 1][j]) + dungeon[i][j];
            }
        }
    return res[dungeon.size() - 1][dungeon[0].size() - 1]+1;
}
int main (){
    int m, n;
    cin >> m >> n;
    vector<vector<int> > dungeon;
    dungeon.resize(m);
    for (int i = 0; i < m;i++){
        dungeon[i].resize(n);
        for (int j = 0; j < n;j++){
            cin >> dungeon[i][j];
        }
    }
    cout<<calculateMinimumHP(dungeon)<<endl;
    return 0;
}