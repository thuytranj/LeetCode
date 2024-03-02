#include <iostream>
using namespace std;

// Runtime 0 ms. Beats 100% of users with C++
// Memory 18.61 MB. Beats 5.66% of users with C++

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
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *head = NULL, *tail = NULL;
    while (list1 != NULL || list2 != NULL)
    {
        if (list1 != NULL && list2 != NULL)
        {
            int min = (list1->val < list2->val) ? list1->val : list2->val;
            insertLast(head, tail, min);
            if (min == list1->val)
                list1 = list1->next;
            else
                list2 = list2->next;
        }
        else if (list1 != NULL)
        {
            insertLast(head, tail, list1->val);
            list1 = list1->next;
        }
        else
        {
            insertLast(head, tail, list2->val);
            list2 = list2->next;
        }
    }
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

    insertLast(head, tail, 1);
    insertLast(head, tail, 2);
    insertLast(head, tail, 4);

    insertLast(head2, tail2, 1);
    insertLast(head2, tail2, 3);
    insertLast(head2, tail2, 4);
    
    ListNode *res = mergeTwoLists(head, head2);
    output(res);
    return 0;
}