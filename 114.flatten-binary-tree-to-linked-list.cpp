#include <iostream>
#include <vector>
#include <map>
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
void flatten(TreeNode *root)
{
    if (root==NULL)
        return;
    while (root) {
        if (root->left)
        {
            TreeNode *tmp = root->left;
            while (tmp->right) tmp=tmp->right;
            tmp->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        root = root->right;
    }
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
    flatten(root);
    while (root){
        cout << root->val << ' ';
        root = root->right;
    }
    cout << endl;
    return 0;
}