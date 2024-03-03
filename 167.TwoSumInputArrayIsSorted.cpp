#include <iostream>
#include <vector>
using namespace std;

// Runtime 223 ms. Beats 9.56% of users with C++
// Memory 352.28 MB. Beats 13.79% of users with C++

int binaryS(vector<int> numbers, int start, int end, int val)
{
    while (start <= end)
    {
        int m = (start + end) / 2;
        if (numbers[m] == val)
            return m;
        else if (numbers[m] < val)
            start = m + 1;
        else
            end = m - 1;
    }
    return -1;
}
vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> res;
    int l = 0, r = numbers.size() - 1;
    while (l <= r)
    {
        if (numbers[l] + numbers[r] == target)
        {
            res.push_back(l + 1);
            res.push_back(r + 1);
            return res;
        }
        int index;
        index = binaryS(numbers, l + 1, r - 1, target - numbers[l]);
        if (index != -1)
        {
            res.push_back(l + 1);
            res.push_back(index + 1);
            return res;
        }
        index = binaryS(numbers, l + 1, r - 1, target - numbers[r]);
        if (index != -1)
        {
            res.push_back(index + 1);
            res.push_back(r + 1);
            return res;
        }
        if (numbers[l] + numbers[r] < target)
            l++;
        else
            r--;
    }
    return res;
}
void output(vector<int> res){
    for (int i=0;i<res.size();i++){
        cout << res[i] << ' ';
    }
}
int main()
{
    vector<int> nums{2, 7, 11, 15};
    int target = 9;
    vector<int> res = twoSum(nums, target);
    output(res);
    return 0;
}