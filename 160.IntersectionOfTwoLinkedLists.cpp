#include <iostream>
#include <set>
using namespace std;

// Runtime 60 ms. Beats 12.61% of users with C++
// Memory 23.72 MB. Beats 5.01% of users with C++

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    set<ListNode *> res;
    ListNode *p = headA;
    while (p != NULL)
    {
        res.insert(p);
        p = p->next;
    }
    p = headB;
    while (p != NULL)
    {
        int lastSize = res.size();
        res.insert(p);
        if (res.size() == lastSize)
            return p;
        p = p->next;
    }
    return NULL;
}
int main (){
    return 0;
}