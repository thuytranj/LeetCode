#include <iostream>
#include <set>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void addTail(ListNode *&head, ListNode *&tail, int val)
{
    ListNode *p = new ListNode(val);
    if (p == NULL)
        return;
    if (head == NULL)
    {
        head = tail = p;
    }
    else
    {
        tail->next = p;
        tail = p;
    }
}
int numComponents(ListNode *head, vector<int> &nums)
{
    vector<int> list;
    ListNode *p = head;
    while (p)
    {
        list.push_back(p->val);
        p = p->next;
    }
    set<int> check;
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = find(list.begin(), list.end(), nums[i]);
        check.insert(it - list.begin());
    }
    int cnt = 0;
    for (auto t = check.begin(); t != check.end(); t++)
    {
        auto tmp = t;
        tmp++;
        if (tmp == check.end() || *tmp - 1 != *t)
            cnt++;
    }
    return cnt;
}
int main()
{
    int n, tmp;
    cin >> n;
    ListNode *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        addTail(head, tail, tmp);
    }
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        nums.push_back(tmp);
    }
    cout << numComponents(head, nums) << endl;
    return 0;
}