#include <iostream>
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
int coutNode(ListNode *head)
{
    if (head == NULL)
        return 0;
    int cnt = 0;
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        cnt++;
    }
    cnt *= 2;
    if (fast)
        cnt++;
    return cnt;
}
ListNode *swapNodes(ListNode *head, int k)
{
    int size = coutNode(head);
    int minIndex = min(k - 1, size - k);
    int maxIndex = max(k - 1, size - k);
    int cnt = 0;
    ListNode *p = head, *first = NULL, *second = NULL;
    while (p && cnt <= maxIndex)
    {
        if (cnt == minIndex)
        {
            first = p;
        }
        if (cnt == maxIndex)
        {
            second = p;
        }
        p = p->next;
        cnt++;
    }
    swap(first->val, second->val);
    return head;
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
    int k;
    cin >> k;
    ListNode *res = swapNodes(head, k);
    printList(res);
    return 0;
}