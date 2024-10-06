#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int val;
    Node *left, *right, *next;
    Node(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
    Node(int x, Node *left, Node *right, Node *next) : val(x), left(left), right(right), next(next) {}
};
Node *connect(Node *root)
{
    if (root == NULL)
        return NULL;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            Node *cur = q.front();
            q.pop();
            if (i != sz - 1)
                cur->next = q.front();
            else
                cur->next = NULL;
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
    }
    return root;
}
int main()
{
    return 0;
}