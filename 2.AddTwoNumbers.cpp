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

// Runtime 15 ms. Beats 88.99% of users with C++
// Memory 75.94 MB. Beats 56.63% of users with C++

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
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *p1 = l1, *p2 = l2, *head = NULL, *tail = NULL;
    int sum = 0, mod = 0;
    while (p1 != NULL || p2 != NULL)
    {
        if (p1 != NULL)
            sum += p1->val;
        if (p2 != NULL)
            sum += p2->val;
        sum += mod;
        if (sum >= 10)
        {
            int unit = sum % 10;
            mod = (sum - unit) / 10;
            insertLast(head, tail, unit);
        }
        else
        {
            insertLast(head, tail, sum);
            mod = 0;
        }
        sum = 0;
        if (p1 != NULL)
            p1 = p1->next;
        if (p2 != NULL)
            p2 = p2->next;
    }
    if (mod != 0)
        insertLast(head, tail, mod);
    return head;
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
    ListNode *head = NULL, *tail = NULL, *head2 = NULL, *tail2 = NULL;

    insertLast(head, tail, 9);
    insertLast(head, tail, 9);
    insertLast(head, tail, 9);
    insertLast(head, tail, 9);
    insertLast(head, tail, 9);
    insertLast(head, tail, 9);
    insertLast(head, tail, 9);

    insertLast(head2, tail2, 9);
    insertLast(head2, tail2, 9);
    insertLast(head2, tail2, 9);
    insertLast(head2, tail2, 9);

    ListNode *res = addTwoNumbers(head, head2);
    output(res);
    return 0;
}