#include <iostream>
#include <vector>
using namespace std;
int triangleNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size(), sum = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            int k = j + 1;
            while (k < n && nums[i] + nums[j] > nums[k])
            {
                k++;
                sum++;
            }
        }
    }
    return sum;
}
int main()
{
    vector<int> nums = {2, 3, 4, 4};
    cout << triangleNumber(nums) << endl;
    return 0;
}