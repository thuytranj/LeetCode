#include <iostream>
using namespace std;

// Runtime 5 ms. Beats 55.67% of users with C++
// Memory 15.18 MB. Beats 50.13% of users with C++

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void insertFirst(ListNode *&head, int val)
{
    ListNode *p = new ListNode;
    p->val = val;
    p->next = head;
    head = p;
}
void insertLast(ListNode *&head, ListNode *&tail, int val)
{
    ListNode *p = new ListNode(val);
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
void deleteTail(ListNode *&head, int &val)
{
    ListNode *p = head;
    if (p->next == NULL)
        head = NULL;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    val = p->next->val;
    p->next = NULL;
}
ListNode *getTail(ListNode *head)
{
    int count = 1;
    ListNode *p = head;
    while (p->next != NULL)
    {
        p = p->next;
        count++;
    }
    return p;
}
int getSize(ListNode *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
ListNode *rotateRight(ListNode *head, int k)
{
    int size = getSize(head), val;
    ListNode *cur = head;
    if (size == 0)
        return NULL;
    int t = k % size;
    for (int i = 0; i < t; i++)
    {
        deleteTail(cur, val);
        insertFirst(cur, val);
    }
    return cur;
}
int main()
{
    ListNode *head = NULL, *tail = NULL;
    insertLast(head, tail, 1);
    insertLast(head, tail, 2);
    insertLast(head, tail, 3);
    insertLast(head, tail, 4);
    insertLast(head, tail, 5);
    int k=2;
    ListNode *res = rotateRight(head, k);
    output(res);
    return 0;
}