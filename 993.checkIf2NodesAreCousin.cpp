#include <iostream>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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
bool checkCousin(TreeNode *root, int val1, int val2)
{
    if (root == NULL)
        return 0;
    queue<TreeNode *> a, b;
    a.push(root);
    while (!a.empty())
    {
        bool check = 0;
        while (!a.empty())
        {
            if ((a.front()->left && (a.front()->left->val == val1 || a.front()->left->val==val2)) || a.front()->right && (a.front()->right->val == val1 || a.front()->right->val == val2))
            {
                cout << a.front()->val << endl;
                if (check == 0)
                    check = 1;
                else
                    return 1;
            }
            if (a.front()->left)
                b.push(a.front()->left);
            if (a.front()->right)
                b.push(a.front()->right);
            a.pop();
        }
        swap(a, b);
    }
    return 0;
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
    int a, b;
    cout << "Nhap a, b: ";
    cin >> a >> b;
    if (checkCousin(root, a, b))
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}