#include <iostream>
#include <queue>
using namespace std;
class MedianFinder
{
public:
    priority_queue<int, vector<int>> left;
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder()
    {
    }
    void balanceHeaps()
    {
        if (right.size() > left.size())
        {
            left.push(right.top());
            right.pop();
        }
        else if (left.size() - 1 > right.size())
        {
            right.push(left.top());
            left.pop();
        }
    }
    void addNum(int x)
    {
        if (left.empty())
        {
            left.push(x);
            return;
        }

        if (x > left.top())
            right.push(x);
        else
            left.push(x);

        balanceHeaps();
    }

    double findMedian()
    {
        if (left.size() == right.size())
            return 1.0 * (left.top() + right.top()) / 2;
        else
            return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main()
{
    MedianFinder *obj = new MedianFinder();
    obj->addNum(1);                    // arr = [1]
    obj->addNum(2);                    // arr = [1, 2]
    cout << obj->findMedian() << endl; // return 1.5 (i.e., (1 + 2) / 2)
    obj->addNum(3);                    // arr[1, 2, 3]
    cout << obj->findMedian() << endl; // return 2.0
    return 0;
}