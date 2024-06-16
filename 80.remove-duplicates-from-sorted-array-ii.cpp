#include <iostream>
#include <vector>
using namespace std;
int findNext(vector<int> nums, int pos)
{
    int i = pos + 1;
    while (i < nums.size() && nums[i] == nums[i - 1])
    {
        i++;
    }
    return i;
}
int removeDuplicates(vector<int> &nums)
{
    int k = 1, i = 1;
    while (i < nums.size())
    {
        if (nums[i] == nums[i - 1])
        {
            nums[k] = nums[i];
            i = findNext(nums, i);
        }
        else
        {
            cout << k << ' ' << i << endl;
            nums[k] = nums[i];
            i++;
        }
        k++;
    }
    return k;
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
    int k = removeDuplicates(nums);
    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << ' ';
    }
    cout << endl;
    return 0;
}