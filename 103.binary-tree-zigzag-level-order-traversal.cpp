#include <iostream>
#include <vector>
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
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    queue<TreeNode *> a, b;
    a.push(root);
    vector<vector<int>> res;
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
        if (!level.empty())
            res.push_back(level);
        if (res.size() % 2 == 0)
            reverse(res.back().begin(), res.back().end());
        a = b;
        b = queue<TreeNode *>();
    }
    return res;
}
int main()
{
    int n, x;
    cin >> n;
    TreeNode *root = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insertNode(root, x);
    }
    vector<vector<int>> res = zigzagLevelOrder(root);
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