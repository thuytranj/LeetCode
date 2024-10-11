#include <iostream>
#include <vector>
#include <queue>
using namespace std;
long long pickGifts(vector<int> &gifts, int k)
{
    priority_queue<int, vector<int>> q(gifts.begin(), gifts.end());
    while (k > 0)
    {
        int tmp = q.top();
        q.pop();
        q.push((int)sqrt(tmp));
        k--;
    }
    long long res = 0;
    while (!q.empty())
    {
        res += q.top();
        q.pop();
    }
    return res;
}
int main()
{
    vector<int> nums = {1, 1, 1, 1};
    int k = 4;
    cout << pickGifts(nums, k) << endl;
    return 0;
}