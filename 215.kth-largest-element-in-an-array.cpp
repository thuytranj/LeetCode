#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>> q(nums.begin(), nums.end());

    while (k > 1 && !q.empty())
    {
        q.pop();
        k--;
    }

    return q.top();
}
int main () {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout<<findKthLargest(nums, k)<<endl;
    return 0;
}