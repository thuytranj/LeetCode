#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > combine(int n, int k)
{
    vector<vector<int> > res;
    vector<int> tmp(k);
    for (int i=0;i<k;i++) {
        tmp[i]=i+1;
    }
    res.push_back(tmp);
    while (1) {
        int j = k - 1;
        while (j>=0 && tmp[j] == n - k + j + 1)
        {
            j--;
        }
        if (j >= 0)
        {
            tmp[j]++;
            for (int i = j + 1; i < k; i++)
            {
                tmp[i] = tmp[i - 1] + 1;
            }
            res.push_back(tmp);
        }
        else break;
    }
    return res;
}
int main () {
    int n, k;
    cin>>n>>k;
    vector<vector<int> > res = combine(n, k);
    for (int i=0;i<res.size();i++) {
        for (int j=0;j<res[i].size();j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}