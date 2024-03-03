#include <iostream>
#include <vector>
using namespace std;

// Runtime 8 ms. Beats 17.93% of users with C++
// Memory 13.5 MB. Beats 18.49% of users with C++

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
ListNode *partition(ListNode *head, int x)
{
    ListNode *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *p = head;
    while (p != NULL)
    {
        if (p->val < x)
            insertLast(head1, tail1, p->val);
        else
            insertLast(head2, tail2, p->val);
        p = p->next;
    }
    if (head1 != NULL && head2 != NULL)
    {
        tail1->next = head2;
        return head1;
    }
    else if (head1 == NULL)
        return head2;
    else
        return head1;
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
    insertLast(head, tail, 4);
    insertLast(head, tail, 3);
    insertLast(head, tail, 2);
    insertLast(head, tail, 5);
    insertLast(head, tail, 2);
    int x =3;
    ListNode *res = partition(head, x);
    output(res);
    return 0;
}