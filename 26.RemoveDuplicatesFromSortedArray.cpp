#include <iostream>
#include <set>
using namespace std;

// Runtime 1 ms. Beats 76.83% of users with C++
// Memory 43.48 MB. Beats 99.98% of users with C++

int removeDuplicates (int nums[], int size)
{
    set<int> res;
    for (int i = 0; i < size; i++)
    {
        res.insert(nums[i]);
    }
    return size - res.size();
}
int main (){
    int nums[] = {1, 1, 2};
    int size = sizeof(nums) / sizeof(nums[0]);
    cout << removeDuplicates(nums, size) << endl;
    return 0;
}