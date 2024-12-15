#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool cmp(vector<int> &a, vector<int> &b)
{
    return (a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]));
}
int scheduleCourse(vector<vector<int>> &courses)
{
    sort(courses.begin(), courses.end(), cmp);
    int total=0;
    priority_queue<int> pq;
    
    for (auto i:courses) {
        int duration = i[0], deadline = i[1];

        if (total+duration<=deadline) {
            total+=duration;
            pq.push(duration);
        }
        else if (!pq.empty() && pq.top()>duration){
            total=total-pq.top()+duration;
            pq.pop();
            pq.push(duration);
        }
    }
    return pq.size();
}
int main()
{
    vector<vector<int>> courses = {{7, 17}, {3, 12}, {10, 20}, {9, 10}, {5, 20}, {10, 19}, {4, 18}};
    cout << scheduleCourse(courses) << endl; // Output: 2
    return 0;
}