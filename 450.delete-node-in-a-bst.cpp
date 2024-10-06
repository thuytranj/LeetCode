#include <iostream>
#include <vector>
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
TreeNode *getMinNode(TreeNode *root)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL)
        return root;
    return getMinNode(root->left);
}
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
        return NULL;
    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left && root->right)
        {
            TreeNode *tmp = getMinNode(root->right);
            root->val = tmp->val;
            root->right = deleteNode(root->right, tmp->val);
        }
        else if (root->left)
        {
            TreeNode *tmp = root->left;
            delete root;
            return tmp;
        }
        else if (root->right)
        {
            TreeNode *tmp = root->right;
            delete root;
            return tmp;
        }
        else
        {
            delete root;
            return NULL;
        }
    }
    return root;
}
void print(TreeNode *root)
{
    if (root == NULL)
        return;
    print(root->left);
    cout << root->val << " ";
    print(root->right);
}
int main()
{
    int n, x;
    cin >> n;
    TreeNode *root = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insert(root, x);
    }
    cout << "Nhap node xoa: ";
    cin >> x;
    root = deleteNode(root, x);
    print(root);
    return 0;
}