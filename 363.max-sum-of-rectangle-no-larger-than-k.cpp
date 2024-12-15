#include <iostream>
#include <vector>
#include <set>
using namespace std;

int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
{
    int n = matrix.size(), m = matrix[0].size(), res = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        vector<int> rowSums(m, 0);
        for (int j = i; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                rowSums[k] += matrix[j][k];
            }

            set<int> prefixSum;
            prefixSum.insert(0);
            int currSum = 0;

            for (int sum : rowSums)
            {
                currSum += sum;
                auto it = prefixSum.lower_bound(currSum - k);
                if (it != prefixSum.end())
                {
                    res = max(res, currSum - *it);
                    if (res == k)
                        return k;
                }
                prefixSum.insert(currSum);
            }
        }
    }

    return res;
}
int main()
{
    vector<vector<int>> matrix = {{2, 2, -1}};
    int k = 0;
    cout << maxSumSubmatrix(matrix, k) << endl;
    return 0;
}