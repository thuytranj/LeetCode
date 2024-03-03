#include <iostream>
#include <vector>
using namespace std;

// Runtime 0 ms. Beats 100% of users with C++
// Memory 9.48 MB. Beats 10.16% of users with C++

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
int getSize(ListNode *head)
{
    ListNode *p = head;
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
void reverseList(ListNode *&head)
{
    ListNode *sau = NULL, *truoc = head;
    while (truoc != NULL)
    {
        ListNode *tmp = truoc->next;
        truoc->next = sau;
        sau = truoc;
        truoc = tmp;
    }
    head = sau;
}
void reorderList(ListNode *head)
{
    int size = getSize(head), pos;
    if (size % 2 == 0)
        pos = size / 2 + 1;
    else
        pos = size / 2 + 2;
    int count = 1;
    ListNode *cur = head;
    for (int i = 1; i <= size; i++)
    {
        if (i == pos)
            break;
        cur = cur->next;
    }
    reverseList(cur);
    ListNode *tmp = head;
    while (cur != NULL)
    {
        ListNode *tmp2 = tmp->next;
        if (cur->next == NULL && size % 2 == 0)
            tmp2 = NULL;
        ListNode *cur2 = cur->next;
        tmp->next = cur;
        cur->next = tmp2;
        cur = cur2;
        tmp = tmp2;
    }
    if (size % 2 != 0)
        tmp->next = NULL;
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
    insertLast(head, tail, 1);
    insertLast(head, tail, 2);
    insertLast(head, tail, 3);
    insertLast(head, tail, 4);
    reorderList(head);
    output(head);
    return 0;
}