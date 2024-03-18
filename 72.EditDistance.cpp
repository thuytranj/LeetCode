#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Runtime 8 ms. Beats 56.91% of users with C++
// Memory 11.91 MB. Beats 51.15% of users with C++

int minDistance(string word1, string word2)
{
    vector<vector<int>> res(word2.size() + 1, vector<int>(word1.size() + 1, 0));

    for (int i = 0; i <= word2.size(); i++)
    {
        res[i][word1.size()] = word2.size() - i;
    }
    for (int i = 0; i <= word1.size(); i++)
    {
        res[word2.size()][i] = word1.size() - i;
    }
    for (int i = word2.size() - 1; i >= 0; i--)
    {
        for (int j = word1.size() - 1; j >= 0; j--)
        {
            if (word2[i] == word1[j])
                res[i][j] = res[i + 1][j + 1];
            else
            {
                res[i][j] = 1 + min(res[i + 1][j], min(res[i][j + 1], res[i + 1][j + 1]));
            }
        }
    }
    return res[0][0];
}
int main()
{
    string word1, word2;
    getline(cin, word1);
    getline(cin, word2);
    cout << minDistance(word1, word2) << endl;
    return 0;
}