#include <iostream>
using namespace std;

// Runtime 8 ms. Beats 29.34% of users with C++
// Memory 12.72 MB. Beats 62.85% of users with C++

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
int countNodeRandom(Node *head, Node *start)
{
    Node *p = head;
    int count = 0;
    while (p != NULL)
    {
        if (p == start->random)
            return count;
        count++;
        p = p->next;
    }
    return count;
}
Node *copyRandomList(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *headNew = new Node(head->val), *p = head->next, *pNew = headNew;
    while (p != NULL)
    {
        Node *cur = new Node(p->val);
        pNew->next = cur;
        p = p->next;
        pNew = pNew->next;
    }
    p = head;
    pNew = headNew;
    while (pNew != NULL)
    {
        int count = countNodeRandom(head, p);
        Node *tmp = headNew;
        for (int i = 0; i < count; i++)
        {
            tmp = tmp->next;
        }
        pNew->random = tmp;
        pNew = pNew->next;
        p = p->next;
    }
    return headNew;
}

int main()
{
    return 0;
}
