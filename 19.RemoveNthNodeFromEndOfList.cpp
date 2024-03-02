#include <iostream>
using namespace std;

// Runtime 3 ms. Beats 65.22% of users with C++
// Memory 13.26 MB. Beats 45.06% of users with C++

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next){} 
};
int countNode(ListNode *head)
{
    int count = 0;
    ListNode *p = head;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    int nums = countNode(head), tmp = 1;
    ListNode *cur = head;
    if (n == nums)
    {
        cur = cur->next;
        return cur;
    }
    ListNode *p = cur;
    while (p != NULL && n + tmp != nums)
    {
        p = p->next;
        tmp++;
    }
    p->next = p->next->next;
    return cur;
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
void output (ListNode *head){
    while (head!=NULL){
        cout << head->val << ' ';
        head = head->next;
    }
    cout<<endl;
}
int main()
{
    ListNode *head = NULL, *tail = NULL;

    insertLast(head, tail, 1);
    insertLast(head, tail, 2);
    insertLast(head, tail, 3);
    insertLast(head, tail, 4);
    insertLast(head, tail, 5);
    insertLast(head, tail, 5);
    int n=2;

    ListNode *res = removeNthFromEnd(head, n);
    output(res);
    return 0;
}