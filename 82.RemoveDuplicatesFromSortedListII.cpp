#include <iostream>
#include <vector>
using namespace std;

// Runtime 7 ms. Beats 41.96% of users with C++
// Memory 14.01 MB. Beats 51.36% of users with C++

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *head1 = head, *cur = head, *front = NULL;
    while (cur != NULL)
    {
        bool same = false;
        ListNode *back = cur;
        for (ListNode *p = cur->next; p != NULL; p = p->next)
        {
            if (p->val == cur->val)
            {
                back->next = p->next;
                p = back;
                same = true;
            }
            else
                back = p;
        }
        if (same)
        {
            if (front == NULL)
            {
                cur = cur->next;
                head1 = head1->next;
            }
            else
            {
                front->next = cur->next;
                cur = front->next;
            }
        }
        else
        {
            front = cur;
            cur = cur->next;
        }
    }
    return head1;
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
int main()
{
    ListNode *head = NULL, *tail = NULL;
    insertLast(head, tail, 1);
    insertLast(head, tail, 2);
    insertLast(head, tail, 3);
    insertLast(head, tail, 3);
    insertLast(head, tail, 4);
    insertLast(head, tail, 4);
    insertLast(head, tail, 5);
    ListNode *res = deleteDuplicates(head);
    output(res);
    return 0;
}