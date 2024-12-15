#include <iostream>
#include <vector>
using namespace std;
int findRadius(vector<int> &houses, vector<int> &heaters)
{
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());

    int r = 0, n = heaters.size();
    for (int i : houses)
    {
        auto pos = lower_bound(heaters.begin(), heaters.end(), i);
        int index = pos - heaters.begin();
        if (index >= n && i - heaters[n - 1] > r)
            r = i - heaters[n - 1];
        else if (index < n)
        {
            if (index == 0 && heaters[index] - i > r)
                r = heaters[index] - i;
            else if (index > 0)
            {
                r = max(r, min(heaters[index] - i, i - heaters[index - 1]));
            }
        }
    }

    return r;
}
int main()
{
    vector<int> houses = {1, 5};
    vector<int> heaters = {2};
    cout << findRadius(houses, heaters) << endl;
    return 0;
}