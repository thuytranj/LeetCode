#include <iostream>
#include <vector>
using namespace std;

// Runtime 4 ms. Beats 93.18% of users with C++
// Memory 15.87 MB. Beats 7.51% of users with C++

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
    ListNode *p =  new ListNode (val);
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
void moveNode(ListNode *&cur, int k, vector<int> &nums)
{
    nums.clear();
    for (int i = 1; i <= k; i++)
    {
        if (cur == NULL)
            return;
        nums.push_back(cur->val);
        cur = cur->next;
    }
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *cur = NULL, *tail = NULL, *p = head;
    vector<int> nums;
    while (p != NULL)
    {
        moveNode(p, k, nums);
        int size = nums.size();
        if (size == k)
        {
            for (int i = size - 1; i >= 0; i--)
            {
                insertLast(cur, tail, nums[i]);
            }
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                insertLast(cur, tail, nums[i]);
            }
        }
    }
    return cur;
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
    int k=2;
    
    ListNode *res = reverseKGroup (head, k);
    output(res);
    return 0;
}