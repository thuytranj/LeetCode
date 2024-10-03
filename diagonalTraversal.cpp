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
void help (TreeNode *root, map<int, vector<int>> &res, int x) {
    if(root==NULL)
        return;
    res[x].push_back(root->val);
    help(root->left, res, x + 1);
    help(root->right, res, x);
}
vector<int> diagonal(TreeNode *root)
{
    if (root == NULL) return vector<int>();
    map<int, vector<int>> res;
    help(root, res, 0);
    vector<int> ans;
    for (auto i = res.begin(); i!=res.end(); i++){
        ans.insert(ans.end(), i->second.begin(), i->second.end());
    }
    return ans;
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
    vector<int> res = diagonal(root);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << ' ';
    cout << endl;
    return 0;
}