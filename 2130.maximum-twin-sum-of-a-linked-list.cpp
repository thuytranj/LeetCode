#include <iostream>
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
void printList(ListNode *head)
{
    ListNode *p = head;
    while (p)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    return;
}
void reverse(ListNode *&head)
{
    ListNode *lst = NULL, *p = head;
    while (p)
    {
        ListNode *tmp = p->next;
        p->next = lst;
        lst = p;
        p = tmp;
    }
    head = lst;
}
int pairSum(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast)
        slow = slow->next;
    reverse(slow);
    ListNode *p = head;
    int Max = INT_MIN;
    while (slow)
    {
        Max = max(Max, slow->val + p->val);
        slow = slow->next;
        p = p->next;
    }
    return Max;
}
int main()
{
    int n;
    cin >> n;
    ListNode *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        addTail(head, tail, tmp);
    }
    cout << pairSum(head) << endl;
    return 0;
}