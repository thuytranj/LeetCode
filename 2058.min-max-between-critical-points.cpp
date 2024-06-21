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
vector<int> nodesBetweenCriticalPoints(ListNode *head)
{
    vector<int> res (2, -1);
    if (head==NULL || head->next==NULL | head->next->next==NULL)
        return res;
    ListNode *p=head->next, *lst=head;
    vector<int> critical;
    int cnt=0;
    while (p->next) {
        if ((p->val<lst->val && p->val<p->next->val) || (p->val>lst->val && p->val>p->next->val))
            critical.push_back(cnt);
        cnt++;
        lst=p;
        p=p->next;
    }
    if (critical.size()>1) {
        res[0] = critical[1] - critical[0];
        for (int i=2;i<critical.size();i++)
            res[0] = min(res[0], critical[i] - critical[i - 1]);
        res[1] = critical[critical.size() - 1] - critical[0];
    }
    return res;
}
int main () {
    int n;
    cin >> n;
    ListNode *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        addTail(head, tail, tmp);
    }
    vector<int> res = nodesBetweenCriticalPoints(head);
    cout<<res[0]<<' '<<res[1]<<endl;
    return 0;
}
