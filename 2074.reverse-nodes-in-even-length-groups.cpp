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
ListNode *reverseEvenLengthGroups(ListNode *head)
{
    vector<int> nums;
    ListNode *p = head;
    while (p)
    {
        nums.push_back(p->val);
        p = p->next;
    }
    int size = 2;
    while ((size - 1) * size / 2 + size < nums.size())
    {
        if (size%2==0) {
            int tmp = (size - 1) * size / 2;
            reverse(nums.begin() + tmp, nums.begin() + tmp + size);
        } 
        size ++;
    }
    if ((nums.size() - (size - 1) * size / 2) % 2 == 0)
    {
        reverse(nums.begin() + (size - 1) * size / 2, nums.end());
    }
    p = NULL;
    ListNode *tail = NULL;
    for (int i = 0; i < nums.size(); i++)
    {
        addTail(p, tail, nums[i]);
    }
    return p;
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
    int n;
    cin >> n;
    ListNode *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        addTail(head, tail, tmp);
    }
    ListNode *res = reverseEvenLengthGroups(head);
    printList(res);
    return 0;
}