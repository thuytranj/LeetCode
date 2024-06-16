#include <iostream>
#include <vector>
using namespace std;
bool canPartition(vector<int> &matchsticks, vector<int> &sides, int index, int target)
{
    if (index == matchsticks.size())
    {
        return sides[0] == target && sides[1] == target && sides[2] == target && sides[3] == target;
    }

    for (int i = 0; i < 4; ++i)
    {
        if (sides[i] + matchsticks[index] <= target)
        {
            sides[i] += matchsticks[index];
            if (canPartition(matchsticks, sides, index + 1, target))
            {
                return true;
            }
            sides[i] -= matchsticks[index];
        }
        if (sides[i] == 0)
            break; // optimization: break if the side is zero
    }
    return false;
}

bool makesquare(vector<int> &matchsticks)
{
    if (matchsticks.empty())
        return false;

    int sum = 0;
    for (int stick : matchsticks)
    {
        sum += stick;
    }

    if (sum % 4 != 0)
        return false;

    int target = sum / 4;
    sort(matchsticks.rbegin(), matchsticks.rend()); // optimization: sort in descending order

    vector<int> sides(4, 0);
    return canPartition(matchsticks, sides, 0, target);
}
int main()
{
    int n;
    cin >> n;
    vector<int> matchsticks(n);
    for (int i = 0; i < n; i++)
    {
        cin >> matchsticks[i];
    }
    if (makesquare(matchsticks))
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}