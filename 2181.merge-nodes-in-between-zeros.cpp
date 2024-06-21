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
ListNode *mergeNodes(ListNode *head)
{
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return NULL;
    ListNode *res = NULL, *tail = NULL;
    int sum = 0;
    ListNode *p = head->next;
    while (p)
    {
        if (p->val == 0)
        {
            if (sum)
            {
                addTail(res, tail, sum);
                sum = 0;
            }
        }
        else
            sum += p->val;
        p = p->next;
    }
    return res;
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
    ListNode *res = mergeNodes(head);
    printList(res);
    return 0;
}