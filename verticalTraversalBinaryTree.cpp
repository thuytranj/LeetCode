#include <iostream>
#include <vector>
#include <map>
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
void help(TreeNode *root, map<int, vector<int>> &orderMap)
{
    if (root == NULL)
        return;
    queue<pair<int, TreeNode *>> a, b;
    a.push(make_pair(0, root));
    while (!a.empty())
    {
        while (!a.empty())
        {
                orderMap[a.front().first].push_back(a.front().second->val);
            if (a.front().second->left)
                b.push(make_pair(a.front().first - 1, a.front().second->left));
            if (a.front().second->right)
                b.push(make_pair(a.front().first + 1, a.front().second->right));
            a.pop();
        }
        swap(a, b);
    }
}

vector<int> verticalOrder(TreeNode *root)
{
    if (root == NULL)
        return vector<int>();
    map<int, vector<int>> orderMap;
    help(root, orderMap);
    vector<int> res;
    for (auto i = orderMap.begin(); i != orderMap.end(); i++)
    {
        res.insert(res.end(), i->second.begin(), i->second.end());
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
    vector<int> res = verticalOrder(root);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << ' ';
    cout << endl;
    return 0;
}