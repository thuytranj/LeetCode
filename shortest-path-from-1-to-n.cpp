#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int minimumStep(int n)
{
    if (n == 1)
        return 0; // Already at 1, no steps needed

    queue<int> q;
    q.push(1);

    std::vector<int> level(n + 1, -1); // Track minimum steps to each point
    level[1] = 0;                      // Start level at 1

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        int currentLevel = level[u];

        // Possible moves: u + 1
        if (u + 1 <= n && level[u + 1] == -1)
        {
            level[u + 1] = currentLevel + 1;
            q.push(u + 1);
            if (u + 1 == n)
                return level[u + 1]; // Early exit if we reach n
        }

        // Possible moves: 3 * u
        if (3 * u <= n && level[3 * u] == -1)
        {
            level[3 * u] = currentLevel + 1;
            q.push(3 * u);
            if (3 * u == n)
                return level[3 * u]; // Early exit if we reach n
        }
    }

    return -1; // In case n is unreachable, though it shouldn’t be in typical cases
}
int main()
{
    cout << minimumStep(887) << endl;
    return 0;
}