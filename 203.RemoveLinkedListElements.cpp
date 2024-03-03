#include <iostream>
using namespace std;

// Runtime 17 ms. Beats 38.56% of users with C++
// Memory 19.34 MB. Beats 5.42% of users with C++

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *removeElements(ListNode *head, int val)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->val == val)
    {
        ListNode *newHead = head->next;
        delete head; // Free the memory of the node to be removed
        return removeElements(newHead, val);
    }
    head->next = removeElements(head->next, val);
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
    insertLast(head, tail, 1);
    insertLast(head, tail, 2);
    insertLast(head, tail, 6);
    insertLast(head, tail, 3);
    insertLast(head, tail, 4);
    insertLast(head, tail, 5);
    insertLast(head, tail, 6);
    int val = 6;
    ListNode *res = removeElements(head, val);
    output(res);
    return 0;
}