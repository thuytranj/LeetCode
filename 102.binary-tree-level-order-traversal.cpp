#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void insertNode(TreeNode *&root, int val)
{
    if (root == NULL)
    {
        root = new TreeNode(val);
        return;
    }
    TreeNode *newNode = new TreeNode(val), *p = root, *lst = NULL;
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
void printTree(TreeNode *root)
{
    if (root == NULL)
        return;
    printTree(root->left);
    cout << root->val << ' ';
    printTree(root->right);
} 
vector<vector<int> > levelOrder(TreeNode *root)
{
    if (root == NULL) return vector<vector<int> > ();
    queue<TreeNode *> a, b;
    vector<vector<int> > res;
    a.push(root);
    while (!a.empty())
    {
        vector<int> level;
        while (!a.empty())
        {
            level.push_back(a.front()->val);
            if (a.front()->left) 
                b.push(a.front()->left);
            if (a.front()->right)
                b.push(a.front()->right);
            a.pop();
        }
        res.push_back(level);
        if (res.size()%2==0) reverse (res[res.size()-1].begin(), res[res.size()-1].end());
        a = b;
        b = queue<TreeNode *>();
    }
    return res;
}
int main()
{
    srand(time(0));
    int n, x;
    cin >> n;
    TreeNode *root = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insertNode(root, x);
    }
    printTree(root);
    cout << endl;
    vector<vector<int> > res = levelOrder(root);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}