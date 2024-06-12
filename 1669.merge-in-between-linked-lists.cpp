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
    if (p == NULL)
        return;
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
ListNode *getTail(ListNode *head)
{
    if (head == NULL)
        return NULL;
    ListNode *p = head;
    while (p->next)
    {
        p = p->next;
    }
    return p;
}
ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
{
    if (list2 == NULL)
        return list1;
    ListNode *first = NULL, *second = NULL, *p = list1;
    int cnt = 0;
    while (p)
    {
        cout << cnt << ' ' << p->val << endl;
        if (cnt == a - 1)
        {
            first = p;
            p=p->next;
        }
        else if (cnt == b + 1)
        {
            second = p;
            break;
        }
        else {
            if (cnt>=a && cnt<=b)
            {
                ListNode *tmp = p->next;
                delete p;
                p = tmp;
            }
            else
                p = p->next;
        }
        cnt++;
    }
    cout << first->val << " " << second->val << endl;
    if (first)
        first->next = list2;
    getTail(list2)->next = second;
    return list1;
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
int main()
{
    ListNode *list1 = NULL, *tail1 = NULL, *list2 = NULL, *tail2 = NULL;
    int n, tmp, a, b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        addTail(list1, tail1, tmp);
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        addTail(list2, tail2, tmp);
    }
    cin >> a >> b;
    ListNode *head = mergeInBetween(list1, a, b, list2);
    printList(head);
    return 0;
}