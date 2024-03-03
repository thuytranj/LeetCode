#include <iostream>
#include <vector>
using namespace std;

// Runtime 3 ms. Beats 95.33% of users with C++
// Memory 15.22 MB. Beats 41.16% of users with C++

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
    ListNode *head1 = head, *cur = head1;
    while (cur != NULL)
    {
        ListNode *back = cur;
        bool same = false;
        bool find = false;
        for (ListNode *p = cur->next; p != NULL; p = p->next)
        {
            if (p->val != cur->val)
            {
                cur->next = back->next;
                find = true;
                break;
            }
            else
                same = true;
            back = p;
        }
        if (same == true && find == false)
            cur->next = NULL;
        cur = cur->next;
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
    insertLast(head, tail, 1);
    insertLast(head, tail, 2);
    ListNode *res = deleteDuplicates(head);
    output(res);
    return 0;
}