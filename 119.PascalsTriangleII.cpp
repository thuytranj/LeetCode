#include <iostream>
#include <vector>
using namespace std;
// Runtime 0 ms. Beats 100% of users with C++
// Memory 7.6 MB. Beats 66.09% of users with C+
vector<int> getRow(int rowIndex)
{
    vector<int> res;
    res.push_back(1);
    if (rowIndex == 0)
        return res;
    res.push_back(1);
    if (rowIndex == 1)
        return res;
    for (int i = 2; i <= rowIndex; i++)
    {
        int tmp = 1;
        for (int j = 1; j < res.size(); j++)
        {
            res[j] += tmp;
            tmp = res[j] - tmp;
        }
        res.push_back(1);
    }
    return res;
}
int main()
{
    int num;
    cin>>num;
    vector<int> res = getRow(num);
    for (int i=0;i<res.size();i++) {
        cout << res[i] << ' ';
    }
    cout<<endl;
    return 0;
}