#include <iostream>
#include <vector>
using namespace std;

// Runtime 8 ms. Beats 89.46% of users with C++
// Memory 13.18 MB. Beats 21.96% of users with C++

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *insertionSortList(ListNode *head)
{
    vector<int> nums;
    ListNode *p = head;
    while (p != NULL)
    {
        nums.push_back(p->val);
        p = p->next;
    }
    sort(nums.begin(), nums.end());
    p = head;
    int i = 0;
    while (p != NULL)
    {
        p->val = nums[i];
        i++;
        p = p->next;
    }
    return head;
}
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
void output(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}
int main()
{
    ListNode *head = NULL, *tail = NULL;
    insertLast(head, tail, 4);
    insertLast(head, tail, 2);
    insertLast(head, tail, 1);
    insertLast(head, tail, 3);
    ListNode *res = insertionSortList(head);
    output(res);
    return 0;
}
