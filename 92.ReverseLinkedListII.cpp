#include <iostream>
#include <vector>
using namespace std;

// Runtime 0 ms. Beats 100% of users with C++
// Memory 9.48 MB. Beats 10.16% of users with C++

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    vector<int> nums;
    ListNode *head1 = NULL, *tail1 = NULL, *p = head;
    int count = 1;
    while (p != NULL)
    {
        if (count >= left && count <= right)
        {
            nums.push_back(p->val);
            if (count == right)
            {
                for (int i = nums.size() - 1; i >= 0; i--)
                {
                    insertLast(head1, tail1, nums[i]);
                }
            }
        }
        else
            insertLast(head1, tail1, p->val);
        count++;
        p = p->next;
    }
    return head1;
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
    insertLast(head, tail, 1);
    insertLast(head, tail, 2);
    insertLast(head, tail, 3);
    insertLast(head, tail, 4);
    insertLast(head, tail, 5);
    int left =2, right=4;
    ListNode *res = reverseBetween(head, left, right);
    output(res);
    return 0;
}
