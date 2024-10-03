#include <iostream>
#include <stack>
#include <vector>
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
void preOrder(TreeNode *root, vector<int> &res)     //NLR
{
    if (root == NULL)
        return;
    stack<TreeNode *> a;
    a.push(root);
    while (!a.empty())
    {
        TreeNode *tmp = a.top();
        a.pop();
        res.push_back(tmp->val);
        if (tmp->right)
            a.push(tmp->right);
        if (tmp->left)
            a.push(tmp->left);
    }
}

void postOrder(TreeNode *root, vector<int> &res)    //reverse NRL
{
    if (root == NULL)
        return;
    stack<TreeNode *> a;
    a.push(root);
    while (!a.empty())
    {
        TreeNode *tmp = a.top();
        a.pop();
        res.push_back(tmp->val);
        if (tmp->left)
            a.push(tmp->left);
        if (tmp->right)
            a.push(tmp->right);
    }
    reverse(res.begin(), res.end());
}
void print(vector<int> res)
{
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << ' ';
    cout << endl;
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
    vector<int> res;
    postOrder(root, res);
    print(res);
    return 0;
}