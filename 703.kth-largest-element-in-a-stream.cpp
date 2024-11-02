#include <iostream>
#include <string>
#include <vector>
using namespace std;
class KthLargest
{
    int k;
    priority_queue<int, vector<int>, greater<int>> q;

public:
    KthLargest(int k, vector<int> nums)
    {
        this->k = k;
        for (int i : nums)
            add(i);
    }

    int add(int val)
    {
        if (q.size() < k || val > q.top())
        {
            q.push(val);
            if (q.size() > k)
                q.pop();
        }
        return q.top();
    }
};

int main()
{
    KthLargest kthLargest(3, vector<int>{4, 5, 8, 2});
    cout << kthLargest.add(3) << endl;  // returns 4
    cout << kthLargest.add(5) << endl;  // returns 5
    cout << kthLargest.add(10) << endl; // returns 5
    cout << kthLargest.add(9) << endl;  // returns 8
    cout << kthLargest.add(4) << endl;  // returns 8
    return 0;
}