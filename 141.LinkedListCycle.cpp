#include <iostream>
#include <set>
using namespace std;

// Runtime 18 ms. Beats 10.23% of users with C++
// Memory 13.73 MB. Beats 8.4% of users with C++

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
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
bool hasCycle(ListNode *head)
{
    ListNode *p = head;
    set<ListNode *> cur;
    while (p != NULL)
    {
        int lastSize = cur.size();
        cur.insert(p);
        if (lastSize == cur.size())
            return true;
        p = p->next;
    }
    return false;
}
int main()
{
    return 0;
}