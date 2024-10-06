#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int val, height;
    Node *left, *right;
    Node(int x) : val(x), height(1), left(NULL), right(NULL) {}
    Node(int x, int h, Node *left, Node *right) : val(x), height(h), left(left), right(right) {}
};
int getHeight(Node *root)
{
    if (!root)
        return 0;
    return root->height;
}
int getBalance(Node *root)
{
    return getHeight(root->left) - getHeight(root->right);
}
Node *leftRotation(Node *root)
{
    if (!root)
        return NULL;
    Node *child = root->right, *children = child->left;
    child->left = root;
    root->right = children;
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}
Node *rightRotation(Node *root)
{
    if (!root)
        return NULL;
    Node *child = root->left, *children = child->right;
    child->right = root;
    root->left = children;
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}
Node *insertAVL(Node *&root, int key)
{
    if (!root)
        return new Node(key);
    if (key < root->val)
        root->left = insertAVL(root->left, key);
    else if (key > root->val)
        root->right = insertAVL(root->right, key);
    else
        return root; // not same key in AVL tree

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1)
    {
        if (key < root->val) // LL case
            return rightRotation(root);
        else // LR case
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }
    else if (balance < -1)
    {
        if (key > root->val) // RR case
            return leftRotation(root);
        else
        { // RL case
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }
    else
        return root;
}

void bfs(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            Node *cur = q.front();
            q.pop();
            cout << cur->val << ' ';
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
        cout << endl;
    }
}
int main()
{
    Node *root = NULL;
    root = insertAVL(root, 1);
    root = insertAVL(root, 2);
    root = insertAVL(root, 3);
    root = insertAVL(root, 4);
    root = insertAVL(root, 5);
    root = insertAVL(root, 6);

    bfs(root);
    return 0;
}