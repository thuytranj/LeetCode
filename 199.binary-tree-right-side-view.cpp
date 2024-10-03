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
vector<int> rightSideView(TreeNode *root)
{
    if (root == NULL)
        return vector<int>();
    queue<TreeNode *> a, b;
    vector<int> res;
    a.push(root);
    while (!a.empty())
    {
        res.push_back(a.back()->val);
        while (!a.empty())
        {
            if (a.front()->left)
                b.push(a.front()->left);
            if (a.front()->right)
                b.push(a.front()->right);
            a.pop();
        }
        swap(a, b);
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
    vector<int> res = rightSideView(root);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << ' ';
    cout << endl;
    return 0;
}