#include <iostream>
#include <vector>
using namespace std;
// Runtime 0 ms. Beats 100% of users with C++
// Memory 7.02 MB. Beats 83.77% of users with C++

int numTrees(int n)
{
    if (n <= 1)
        return 1;
    vector<int> res(n + 1, 0);
    res[0] = res[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            res[i] += res[j - 1] * res[i - j];
        }
    }
    return res[n];
}
int main()
{
    int n;
    cin >> n;
    cout << numTrees(n) << endl;
    return 0;
}