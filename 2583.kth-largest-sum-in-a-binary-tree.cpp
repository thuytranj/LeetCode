#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void insert(TreeNode *&root, int val)
{
    if (root == NULL)
    {
        root = new TreeNode(val);
        return;
    }
    TreeNode *p = root, *lst = NULL;
    TreeNode *newNode = new TreeNode(val);
    while (p)
    {
        lst = p;
        if (val < p->val)
            p = p->left;
        else
            p = p->right;
    }
    if (val < lst->val)
        lst->left = newNode;
    else
        lst->right = newNode;
}
long long kthLargestLevelSum(TreeNode *root, int k)
{
    if (root == NULL)
        return 0;
    vector<long long> res;
    queue<TreeNode *> q;
    q.push(root);
    int cnt = 0;
    while (!q.empty())
    {
        int sz = q.size();
        long long sum = 0;
        for (int i = 0; i < sz; i++)
        {
            TreeNode *cur = q.front();
            q.pop();
            sum += cur->val;
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
        cout << sum << endl;
        res.push_back(sum);
        cnt++;
    }
    sort(res.begin(), res.end(), greater<long long>());
    if (k <= res.size())
        return res[k - 1];
    else
        return -1;
}
int main()
{
    int n, x;
    // cin >> n;
    // TreeNode *root = NULL;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> x;
    //     insert(root, x);
    // }
    TreeNode *root = new TreeNode(605481);
    root->right = new TreeNode(87336);
    root->right->right = new TreeNode(226750);
    cin >> x;
    cout << kthLargestLevelSum(root, x) << endl;
    return 0;
}