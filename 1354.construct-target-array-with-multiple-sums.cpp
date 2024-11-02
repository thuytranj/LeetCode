#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isPossible(vector<int> &target)
{
    priority_queue<long long> maxQueue;

    long long sum = 0;
    for (int i = 0; i < target.size(); i++)
    {
        sum += target[i];
        maxQueue.push(target[i]);
    }

    long long maxElements, remSum, element;
    while (maxQueue.top() != 1)
    {
        maxElements = maxQueue.top();
        maxQueue.pop();

        remSum = sum - maxElements;
        if (remSum <= 0 || remSum >= maxElements)
            return 0;

        element = maxElements % remSum;
        if (element == 0)
        {
            if (remSum != 1)
                return 0;
            else
                return 1;
        }
        sum = remSum + element;

        maxQueue.push(element);
    }
    return 1;
}

int main()
{
    vector<int> target = {1, 1, 1, 2};
    if (isPossible(target))
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}