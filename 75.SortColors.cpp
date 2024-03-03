#include <iostream>
#include <vector>
using namespace std;

// Runtime 2 ms. Beats 43.72% of users with C++
// Memory 9.82 MB. Beats 23.93% of users with C++

int partition(vector<int> &nums, int start, int end)
{
    int pivot = nums[end], i = start - 1, j = start;
    while (j < end)
    {
        if (nums[j] < pivot)
        {
            i++;
            swap(nums[i], nums[j]);
        }
        j++;
    }
    i++;
    swap(nums[i], nums[end]);
    return i;
}
void quickSort(vector<int> &nums, int start, int end)
{
    if (end <= start)
        return;
    int pi = partition(nums, start, end);
    quickSort(nums, start, pi - 1);
    quickSort(nums, pi + 1, end);
}
void sortColors(vector<int> &nums)
{
    quickSort(nums, 0, nums.size() - 1);
}
void output (vector<int> nums){
    for (int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    cout<<endl;
}
int main()
{
    vector<int> nums{2, 0, 2, 1, 1, 0};
    sortColors(nums);
    output(nums);
    return 0;
}