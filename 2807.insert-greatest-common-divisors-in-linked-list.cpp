#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void addTail(ListNode *&head, ListNode *&tail, int val)
{
    ListNode *p = new ListNode(val);
    if (head == NULL)
    {
        head = tail = p;
    }
    else
    {
        tail->next = p;
        tail = p;
    }
}
void printList(ListNode *head)
{
    ListNode *p = head;
    while (p)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    return;
}
ListNode *insertGreatestCommonDivisors(ListNode *head)
{
    if (head==NULL || head->next==NULL) return NULL; 
    ListNode* p=head;
    while (p->next) {
        ListNode* cur=p->next;
        ListNode *tmp = new ListNode(__gcd(p->val, p->next->val));
        tmp->next=p->next;
        p->next=tmp;
        p=cur;
    }
    return head;
}
int main()
{
    int n;
    cin >> n;
    ListNode *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        addTail(head, tail, tmp);
    }
    ListNode *res = insertGreatestCommonDivisors (head);
    printList(res);
    return 0;
}