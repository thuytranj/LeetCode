#include <iostream>
#include <vector>
using namespace std;
void wiggleSort(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size(), j = n - 1, i = (n % 2 == 0) ? n / 2 - 1 : n / 2;
    vector<int> arr(n);
    for (int k = 0; k < n; k++)
    {
        if (k % 2 == 0)
            arr[k] = nums[i--];
        else
            arr[k] = nums[j--];
    }
    nums = arr;
}
int main()
{
    vector<int> nums = {4, 5, 5, 6};
    wiggleSort(nums);
    for (int i : nums)
        cout << i << ' ';
    cout << endl;
    return 0;
}