#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > generateMatrix(int n)
{
    vector<vector<int> > res(n, vector<int>(n, 0));
    int left=0, right=n-1, top=0, bot=n-1;
    int i=1;
    while (i<=n*n) {
        for (int j=left;j<=right;j++) {
            res[top][j]=i;
            i++;
            if (i>n*n) return res;
        }
        for (int j=top+1;j<bot;j++) {
            res[j][right] = i;
            i++;
            if (i > n * n)
                return res;
        }
        for (int j=right;j>=left;j--){
            res[bot][j]=i;
            i++;
            if (i > n * n)
                return res;
        }
        for (int j=bot-1;j>top;j--){
            res[j][left]=i;
            i++;
            if (i > n * n)
                return res;
        }
        left++;
        right--;
        top++;
        bot--;
    }
    return res;
}
int main () {
    int n;
    cin>>n;
    vector<vector<int> > res = generateMatrix(n);
    for (int i=0;i<res.size();i++) {
        for (int j=0;j<res[i].size();j++) {
            cout<<res[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}