#include <iostream>
#include <map>
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
    if (p == NULL)
        return;
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
    if (head == NULL)
    {
        cout << "NULL\n";
        return;
    }
    ListNode *p = head;
    while (p != NULL)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}
bool check(vector<int> nums, int &start, int &end)
{
    vector<int> sum(nums.size(), 0);
    sum[0] = nums[0];
    if (sum[0] == 0)
    {
        start = 0;
        end = 0;
        return 1;
    }
    for (int i = 1; i < nums.size(); i++)
    {
        sum[i] = sum[i - 1] + nums[i];
        if (sum[i] == 0)
        {
            start = 0;
            end = i;
            return true;
        }
        else
        {
            for (int j = 0; j < i; j++)
            {
                if (sum[i] == sum[j])
                {
                    start = j + 1;
                    end = i;
                    return true;
                }
            }
        }
    }
    return false;
}
ListNode *removeZeroSumSublists(ListNode *head)
{
    ListNode *p = head;
    vector<int> nums;
    while (p)
    {
        nums.push_back(p->val);
        p = p->next;
    }
    int start = -1, end = -1;
    while (check(nums, start, end))
    {
        if (start == 0 && end == nums.size() - 1)
        {
            return NULL;
        }
        nums.erase(nums.begin() + start, nums.begin() + end + 1);
    }
    ListNode *resHead = NULL, *tail = NULL;
    for (int i = 0; i < nums.size(); i++)
    {
        addTail(resHead, tail, nums[i]);
    }
    return resHead;
}
int main()
{
    ListNode *head = NULL, *tail = NULL;
    int n, tmp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        addTail(head, tail, tmp);
    }
    printList(removeZeroSumSublists(head));
    return 0;
}