#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){} 
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};
void addTail(ListNode *&head, ListNode *&tail, int val)
{
    ListNode *p = new ListNode(val);
    if (p == NULL)
        return;
    if (head==NULL)
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
}
vector<ListNode *> splitListToParts(ListNode *head, int k)
{
    ListNode *p = head;
    vector<ListNode *> res;
    vector<int> nums;
    while (p)
    {
        nums.push_back(p->val);
        p = p->next;
    }
    res.resize(k, nullptr);
    int size = nums.size() / k, mem = nums.size() % k;
    int j = 0;
    for (int i = 0; i < k; i++)
    {
        if (j>=nums.size())
            break;
        ListNode *tail = NULL;
        int tmp = size;
        if (i < mem)
            tmp++;
        for (int t = j; t < j+tmp;t++) {
            addTail(res[i], tail, nums[t]);
        }
        j += tmp;
    }
    return res;
}

int main () {
    ListNode *head = NULL, *tail=NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        addTail(head, tail, tmp);
    }
    printList(head);
    int k;
    cin >> k;
    vector<ListNode *> res=splitListToParts(head, k);
    for (int i = 0; i < k; i++) {
        printList(res[i]);
    }
    return 0;
}