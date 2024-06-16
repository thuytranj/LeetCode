#include <iostream>
#include <set> 
using namespace std;
void setZeroes(vector<vector<int> > &matrix)
{
    set<int> row, col;
    for (int i=0;i<matrix.size();i++) {
        for (int j=0;j<matrix[i].size();j++) {
            if (matrix[i][j] == 0) {
                row.insert(i);
                col.insert(j);
            }
        }
    }
    for (auto it = row.begin(); it != row.end(); it++)
    {
        for (int j=0;j<matrix[0].size();j++) {
            matrix[*it][j]=0;
        }
    }
    for (auto it = col.begin(); it != col.end(); it++)
    {
        for (int j=0;j<matrix.size();j++) {
            matrix[j][*it]=0;
        }
    }
}
int main () {
    int row, col;
    cin>>row>>col;
    vector<vector<int> > matrix(row);
    for (int i=0;i<row;i++) {
        matrix[i].resize(col);
        for (int j=0;j<col;j++) {
            cin>>matrix[i][j];
        }
    }
    setZeroes(matrix);
    for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
            cout << matrix[i][j] << ' ';
        }
        cout<<endl;
    }
    return 0;
}