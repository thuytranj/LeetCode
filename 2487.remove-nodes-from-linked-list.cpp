#include <iostream>
#include <vector>
#include <stack>
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
void addHead(ListNode *&head, int val)
{
    ListNode *p = new ListNode(val);
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        p->next = head;
        head = p;
    }
}
ListNode *removeNodes(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *p = head, *res = NULL;
    stack<int> val;
    while (p)
    {
        while (!val.empty() && p->val > val.top())
        {
            val.pop();
        }
        val.push(p->val);
        p = p->next;
    }
    while (!val.empty())
    {
        addHead(res, val.top());
        val.pop();
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
    ListNode *res = removeNodes(head);
    printList(res);
    return 0;
}