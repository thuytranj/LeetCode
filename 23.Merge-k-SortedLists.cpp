#include <iostream>
#include <vector>
using namespace std;

// Runtime 252 ms. Beats 5.07% of users with C++
// Memory 342.01 MB. Beats 5.18% of users with C++

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
int findIndex(vector<ListNode *> lists, int size)
{
    int min, index;
    for (int i = 0; i < size; i++)
    {
        if (lists[i] != NULL)
        {
            min = lists[i]->val;
            index = i;
            break;
        }
    }
    for (int i = index + 1; i < size; i++)
    {
        if (lists[i] != NULL && lists[i]->val < min)
        {
            min = lists[i]->val;
            index = i;
        }
    }
    return index;
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
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *head = NULL, *tail = NULL;
    int size = lists.size(), sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += getSize(lists[i]);
    }
    for (int j = 0; j < sum; j++)
    {
        int index = findIndex(lists, size);
        insertLast(head, tail, lists[index]->val);
        lists[index] = lists[index]->next;
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
    ListNode *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *head3 = NULL, *tail3 = NULL;
    insertLast(head1, tail1, 1);
    insertLast(head1, tail1, 4);
    insertLast(head1, tail1, 5);

    insertLast(head2, tail2, 1);
    insertLast(head2, tail2, 3);
    insertLast(head2, tail2, 4);

    insertLast(head3, tail3, 2);
    insertLast(head3, tail3, 6);

    vector<ListNode*> cur;
    cur.push_back(head1);
    cur.push_back(head2);
    cur.push_back(head3);
    
    ListNode *res = mergeKLists(cur);
    output(res);
    return 0;
}