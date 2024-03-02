#include <iostream>
#include <vector>
using namespace std;

// Runtime 4 ms. Beats 39.28% of users with C++
// Memory 9.4 MB. Beats 59.46% of users with C++

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
ListNode *swapPairs(ListNode *head)
{
    ListNode *cur = NULL, *tail = NULL, *p = head;
    while (p != NULL)
    {
        if (p->next != NULL)
            insertLast(cur, tail, p->next->val);
        insertLast(cur, tail, p->val);
        if (p->next != NULL)
            p = p->next->next;
        else
            p = NULL;
    }
    return cur;
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
    ListNode *res = swapPairs(head);
    output(res);
    return 0;
}