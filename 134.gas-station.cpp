#include <iostream>
#include <vector>
using namespace std;
int sum (vector<int> nums) {
    int sum=0;
    for (int i=0;i<nums.size();i++) {
        sum += nums[i];
    }
    return sum;
}
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    if (sum(gas)<sum(cost)) return -1;
    int total=0, res=0;
    for (int i=0;i<gas.size();i++) {
        total += gas[i] - cost[i];
        if (total<0) {
            total=0;
            res=i+1;
        }
    }
    return res;
}
int main () {
    int n;
    cin >> n;
    vector<int> gas(n);
    for (int i=0;i<n;i++)
        cin >> gas[i];
    vector<int> cost(n);
    for (int i=0;i<n;i++) {
        cin >> cost[i];
    }
    cout << canCompleteCircuit(gas, cost) << endl;
    return 0;
}