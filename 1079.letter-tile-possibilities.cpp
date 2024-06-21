#include <iostream>
#include <string>
#include <set>
using namespace std;
void solve(string tiles, int size, set<string> &res, vector<bool> &check, string cur)
{
    if (cur.size() == size)
    {
        res.insert(cur);
        return;
    }
    for (int j = 0; j < tiles.size(); j++)
    {
        if (check[j] == 0)
        {
            check[j] = 1;
            solve(tiles, size, res, check, cur +tiles[j]);
            check[j] = 0;
        }
    }
}
int numTilePossibilities(string tiles)
{
    set<string> res;
    vector<bool> check(tiles.size(), 0);

    for (int i = 1; i <= tiles.size(); i++)
    {
        solve(tiles, i, res, check, "");
    }
    return res.size();
}

int main()
{
    string tiles;
    getline(cin, tiles);
    cout << numTilePossibilities(tiles) << endl;
    return 0;
}