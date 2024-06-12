#include <iostream>
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
int findIndex(vector<int> nums, int start, int val)
{
    for (int i = start; i < nums.size(); i++)
    {
        if (nums[i] > val)
            return i;
    }
    return -1;
}
vector<int> nextLargerNodes(ListNode *head)
{
    vector<int> nums, res;
    ListNode *p = head;
    while (p)
    {
        nums.push_back(p->val);
        p = p->next;
    }
    res.resize(nums.size());
    for (int i = 0; i < res.size(); i++)
    {
        int it = findIndex(nums, i + 1, nums[i]);
        if (it != -1)
            res[i] = nums[it];
        else
            res[i] = 0;
    }
    return res;
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
    vector<int> res = nextLargerNodes(head);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << ' ';
    cout << endl;
    return 0;
}