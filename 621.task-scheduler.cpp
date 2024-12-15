#include <iostream>
#include <vector>
#include <map>
using namespace std;
int leastInterval(vector<char> &tasks, int n)
{
    map<char, int> m;
    int maxCount = 0, maxfre = 0;
    for (char c : tasks)
    {
        m[c]++;
        maxCount = max(maxCount, m[c]);
    }
    for (auto i : m)
    {
        if (i.second == maxCount)
            maxfre++;
    }

    int partCount = maxCount - 1;
    int partLength = n - (maxfre - 1);
    int emptySlots = partCount * partLength;
    int remainingTasks = tasks.size() - maxCount * maxfre;
    int add = max(0, emptySlots - remainingTasks);
    return tasks.size() + add;
}
int main()
{
    vector<char> tasks = {'A', 'C', 'A', 'B', 'D', 'B'};
    int n = 1;
    cout << leastInterval(tasks, n) << endl;
    return 0;
}