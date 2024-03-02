#include <iostream>
#include <vector>
using namespace std;

// Runtime 205 ms. Beats 5.04% of users with C++
// Memory 90.08 MB. Beats 83.09% of users with C++

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int temp;
    for (int i = 0; i < nums2.size(); i++)
    {
        temp = nums2[i];
        nums1.emplace_back(temp);
    }
    for (int i = 0; i < nums1.size() - 1; i++)
    {
        for (int j = i + 1; j < nums1.size(); j++)
        {
            if (nums1[j] < nums1[i])
                swap(nums1[i], nums1[j]);
        }
    }
    if (nums1.size() % 2 == 0)
    {
        return (double)(nums1[nums1.size() / 2 - 1] + nums1[nums1.size() / 2]) / 2;
    }
    else
        return (double)nums1[nums1.size() / 2];
}
int main()
{
    vector<int> nums1{1, 2}, nums2{3, 4};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}