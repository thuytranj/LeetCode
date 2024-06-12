#include <iostream>
#include <vector>
using namespace std;
int maxProduct(vector<int> &nums)
{
    vector<int> product(nums.size());
    product[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        int tmp = nums[i], Max = nums[i];
        for (int j = i - 1; j >= 0; j--)
        {
            tmp *= nums[j];
            if (tmp > Max)
                Max = tmp;
        }
        product[i] = max(nums[i], max (Max, product[i-1]));
    }
    return product[product.size() - 1];
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << maxProduct(a) << endl;
    return 0;
}