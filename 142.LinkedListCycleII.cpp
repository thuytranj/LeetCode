#include <iostream>
#include <set>
using namespace std;

// Runtime 14 ms. Beats 10.09% of users with C++
// Memory 12.5 MB. Beats 9.87% of users with C++

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *detectCycle(ListNode *head)
{
    ListNode *p = head;
    set<ListNode *> cur;
    int lastSize = 0;
    while (p != NULL)
    {
        lastSize = cur.size();
        cur.insert(p);
        if (cur.size() == lastSize)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
int main()
{
    return 0;
}