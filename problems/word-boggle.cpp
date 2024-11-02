#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool check(const vector<vector<char>> &board, vector<vector<bool>> &vis, const vector<pair<int, int>> &dir, const string& word, int r, int c, int cnt)
{
    if (cnt == word.size())
    {
        return 1;
    }

    vis[r][c] = true;

    for (const auto &i : dir)
    {
        int newR = r + i.first;
        int newC = c + i.second;

        if (newR >= 0 && newR < board.size() && newC >= 0 && newC < board[0].size() && board[newR][newC] == word[cnt] && !vis[newR][newC])
        {
            if (check(board, vis, dir, word, newR, newC, cnt + 1))
            {
                return 1;
            }
        }
    }
    vis[r][c] = false;
    return false;
}
vector<string> wordBoggle(vector<vector<char>> &board, vector<string> &dictionary)
{
    int n = board.size(), m = board[0].size();
    vector<pair<int, int>> dir{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    unordered_map<char, vector<string>> words;
    unordered_set<string> res;
    vector<string> result;

    for (const auto &word : dictionary)
    {
        words[word[0]].push_back(word);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (words.find(board[i][j]) != words.end())
            {
                for (const auto &word : words[board[i][j]])
                {
                    if (res.find (word) == res.end())
                    {
                        vector<vector<bool>> vis(n, vector<bool>(m, false));
                        if (check(board, vis, dir, word, i, j, 1)) {
                            res.insert(word);
                            result.push_back(word);
                        }
                    }
                }
            }
        }
    }

    return result;
}
int main()
{
    vector<vector<char>> board = {{'d', 'b'}, {'b', 'f'}, {'e', 'c'}, {'b', 'c'}, {'d', 'c'}};
    vector<string> dictionary = {"bcd", "db"};
    vector<string> res = wordBoggle(board, dictionary);

    for (const auto &s : res)
        cout << s << endl;
    return 0;
}