#include <iostream>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void insertNode(TreeNode *&root, int val)
{
    TreeNode *newNode = new TreeNode(val);
    if (root == NULL)
    {
        root = newNode;
        return;
    }
    TreeNode *p = root, *lst = NULL;
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
vector<int> topViewOfBinaryTree(TreeNode *root)
{
    if (root == NULL)
        return vector<int>();
    queue<pair<int, TreeNode *>> q, t;
    int l = 0, r = 0;
    q.push(pair<int, TreeNode *>(0, root));
    vector<int> res;
    res.push_back(root->val);
    while (!q.empty())
    {
        while (!q.empty())
        {
            if (q.front().first < l)
            {
                l = q.front().first;
                res.insert(res.begin(), q.front().second->val);
            }
            else if (q.front().first > r)
            {
                r = q.front().first;
                res.insert(res.end(), q.front().second->val);
            }
            if (q.front().second->left)
                t.push(make_pair(q.front().first - 1, q.front().second->left));
            if (q.front().second->right)
                t.push(make_pair(q.front().first + 1, q.front().second->right));
            q.pop();
        }
        swap(q, t);
    }
    return res;
}
int main()
{
    TreeNode *root = NULL;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insertNode(root, x);
    }
    vector<int> res = topViewOfBinaryTree(root);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << ' ';
    cout << endl;
    return 0;
}