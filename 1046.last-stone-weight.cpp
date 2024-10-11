#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int lastStoneWeight(vector<int> &stones)
{
    priority_queue<int, vector<int>> q(stones.begin(), stones.end());

    while (q.size() > 1)
    {
        int y = q.top();
        q.pop();
        int x = q.top();
        q.pop();
        if (x != y)
            q.push(y - x);
    }
    return q.empty() ? 0 : q.top();
}
int main()
{
    vector<int> stones = {1};
    cout << lastStoneWeight(stones) << endl;
    return 0;
}