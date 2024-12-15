#include <iostream>
#include <vector>
using namespace std;
vector<int> countSort (vector<int> &nums, int exp) {
    vector<int> cout(10, 0);
    for (int i:nums) {
        cout[(i / exp) % 10]++;
    }
    for (int i=1; i<10; i++) {
        cout[i] += cout[i-1];
    }
    vector<int> res(nums.size());
    for (int i=nums.size()-1; i>=0; i--) {
        res[cout[(nums[i] / exp) % 10] - 1] = nums[i];
        cout[(nums[i] / exp) % 10]--;
    }
    return res;
}

void radixSort (vector<int> &nums) {
    int maxNum = *max_element(nums.begin(), nums.end());
    for (int exp = 1; maxNum / exp > 0; exp *= 10) {
        nums = countSort(nums, exp);
    }
}
int maximumGap(vector<int> &nums)
{
    if (nums.size() < 2)
        return 0;
        
    radixSort(nums);
    int res = nums[1] - nums[0];

    for (int i=2;i<nums.size();i++) {
        res = max(res, nums[i] - nums[i - 1]);
    }
    return res;
}
int main () {
    vector<int> nums{10, 5, 2, 15, 3, 20};
    cout << "Maximum Gap: " << maximumGap(nums) << endl;
    return 0;
}