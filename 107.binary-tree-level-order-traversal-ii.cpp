#include <iostream>
#include <queue>
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
vector<vector<int>> levelOrderBottom(TreeNode *root)
{
    if (root == NULL)
        return vector<vector<int>>();
    queue<TreeNode *> a, b;
    vector<vector<int>> res;
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
        swap(a, b);
    }
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    srand(time(0));
    TreeNode *root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        insertNode(root, rand() % 100 + 1);
    }
    vector<vector<int>> res = levelOrderBottom(root);
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