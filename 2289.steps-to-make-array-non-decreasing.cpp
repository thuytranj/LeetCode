#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// bool help(vector<int> &nums)
// {
//     int i = nums.size() - 1;
//     bool res = 1;
//     while (i >= 1)
//     {
//         if (nums[i] < nums[i - 1])
//         {
//             nums.erase(nums.begin() + i);
//             res = 0;
//         }
//         i--;
//     }
//     return res;
// }
// int totalSteps(vector<int> &nums)
// {
//     int cnt = 0;
//     while (help(nums) == 0)
//     {
//         cnt++;
//     }
//     return cnt;
// }

int totalSteps(vector<int> &nums)
{
    int n = nums.size();
    vector<int> steps(n, 0); // steps[i] means the steps needed to remove nums[i]
    stack<int> s;            // this stack keeps track of indices

    for (int i = 0; i < n; ++i)
    {
        int max_steps = 0;
        // Process elements in stack which are smaller than the current element
        while (!s.empty() && nums[s.top()] <= nums[i])
        {
            max_steps = max(max_steps, steps[s.top()]);
            s.pop();
        }
        // If stack is not empty, it means nums[i] will be removed in the future, so increment the steps count
        if (!s.empty())
        {
            steps[i] = max_steps + 1;
        }
        s.push(i);
    }

    return *max_element(steps.begin(), steps.end());
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << totalSteps(nums) << endl;
    return 0;
}