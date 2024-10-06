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
void help (vector<TreeNode*> trees, set<int> &vis, int pos, int index, map<TreeNode*, TreeNode*> &parents, TreeNode* &root){
    if (pos==trees.size()) {
        root=
    }
}
TreeNode *canMerge(vector<TreeNode *> &trees) {
}
int main()
{
    int n;
    cin >> n;
    vector<TreeNode*> trees(n);
    for (int i = 0; i < n;i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            insert(trees[i], x);
        }
    }
    return 0;
}