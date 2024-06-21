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
vector<vector<int> > spiralMatrix(int m, int n, ListNode *head)
{
    vector<vector<int> > res(m, vector<int>(n, -1));
    ListNode *p = head;
    int top = 0, bot = m - 1, left = 0, right = n - 1;
    while (top <= bot && p)
    {
        for (int i = left; i <= right; i++)
        {
            res[top][i] = p->val;
            p = p->next;
            if (p == NULL)
                return res;
        }
        for (int i = top + 1; i < bot; i++)
        {
            res[i][right] = p->val;
            p = p->next;
            if (p == NULL)
                return res;
        }
        for (int i = right; i >= left; i--)
        {
            res[bot][i] = p->val;
            p = p->next;
            if (p == NULL)
                return res;
        }
        for (int i = bot - 1; i > top; i--)
        {
            res[i][left] = p->val;
            p = p->next;
            if (p == NULL)
                return res;
        }
        top++;
        bot--;
        left++;
        right--;
        // cout<<1<<endl;
    }
    return res;
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
    int m;
    cin >> m >> n;
    vector<vector<int> > res = spiralMatrix(m, n, head);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}