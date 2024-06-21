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
ListNode *doubleIt(ListNode *head)
{
    ListNode* p=head;
    vector<int> nums;
    while (p) {
        nums.push_back(p->val);
        p = p->next;
    }
    vector<int> cur(nums.size() + 1, -1);
    int mem=0;
    for (int i=cur.size()-1;i>0;i--) {
        cur[i]=(2*nums[i-1]+mem)%10;
        mem=(2*nums[i-1]+mem)/10;
    }
    if (mem) cur[0]=mem;
    ListNode* res=NULL, *tail=NULL;
    if (cur[0]>0)
        addTail(res, tail, cur[0]);
    for (int i=1;i<cur.size();i++) {
       addTail(res, tail, cur[i]);
    }
    return res;
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
    ListNode *res = doubleIt(head);
    printList(res);
    return 0;
}