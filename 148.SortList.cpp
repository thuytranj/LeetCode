#include <iostream>
#include <vector>
using namespace std;

// Runtime 95 ms. Beats 99.88% of users with C++
// Memory 56.7 MB. Beats 76.38% of users with C++

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *sortList(ListNode *head)
{
    ListNode *p = head;
    vector<int> nums;
    while (p != NULL)
    {
        nums.push_back(p->val);
        p = p->next;
    }
    sort(nums.begin(), nums.end());
    p = head;
    for (auto i : nums)
    {
        p->val = i;
        p = p->next;
    }
    return head;
}
void insertLast(ListNode *&head, ListNode *&tail, int val)
{
    ListNode *p = new ListNode;
    p->val = val;
    p->next = NULL;
    if (tail == NULL)
    {
        head = p;
        tail = p;
    }
    else
    {
        tail->next = p;
        tail = p;
    }
}
void output(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}
int main()
{
    ListNode *head = NULL, *tail = NULL;
    insertLast(head, tail, -1);
    insertLast(head, tail, 5);
    insertLast(head, tail, 3);
    insertLast(head, tail, 4);
    insertLast(head, tail, 0);
    ListNode *res = sortList(head);
    output(res);
    return 0;
}