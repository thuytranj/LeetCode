#include <iostream>
#include <vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int> > &matrix)
{
    int rowTop = 0, rowBot = matrix.size() - 1, colL = 0, colR = matrix[0].size() - 1, cnt = 0, size=matrix.size()*matrix[0].size();
    vector<int> res;
    while (rowTop <= rowBot || colL <= colR)
    {
        for (int i = colL; i <= colR; i++) {
            res.push_back(matrix[rowTop][i]);
            cnt++;
            if (cnt == size)
                return res;
        }
        rowTop++;
        for (int i = rowTop; i <= rowBot; i++) {
            res.push_back(matrix[i][colR]);
            cnt++;
            if (cnt == size)
                return res;
        }
        colR--;
        for (int i = colR; i >= colL; i--) {
            res.push_back(matrix[rowBot][i]);
            cnt++;
            if (cnt == size)
                return res;
        }
        rowBot--;
        for (int i = rowBot; i >= rowTop; i--){
            res.push_back(matrix[i][colL]);
            cnt++;
            if (cnt == size)
                return res;
        }
        colL++;
    }
    return res;
}
int main()
{
    vector<vector<int> > matrix;
    int m, n;
    cin >> m >> n;
    matrix.resize(m);
    for (int i = 0; i < m;i++){
        matrix[i].resize(n);
        for (int j = 0; j < n;j++) {
            cin >> matrix[i][j];
        }
    }
    vector<int> res = spiralOrder(matrix);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}