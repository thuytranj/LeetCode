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
    if (!root)
        return 0;
    return getHeight(root->left) - getHeight(root->right);
}
Node *leftRotation(Node *root)
{
    if (!root)
        return NULL;
    Node *child = root->right;
    Node *childLeft = child->left;
    child->left = root;
    root->right = childLeft;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child;
}
Node *rightRotation(Node *root)
{
    if (!root)
        return NULL;
    Node *child = root->left;
    Node *childRight = child->right;
    child->right = root;
    root->left = childRight;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child;
}
Node *insertToAVL(Node *node, int data)
{
    if (!node)
        return new Node(data);
    else if (data < node->val)
        node->left = insertToAVL(node->left, data);
    else if (data > node->val)
        node->right = insertToAVL(node->right, data);
    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->val)
        return rightRotation(node);

    else if (balance < -1 && data > node->right->val)
        return leftRotation(node);

    else if (balance > 1 && data > node->left->val)
    {
        node->left = leftRotation(node->left);
        return rightRotation(node);
    }

    else if (balance < -1 && data < node->right->val)
    {
        node->right = rightRotation(node->right);
        return leftRotation(node);
    }
    else
        return node;
}
Node *getMinNode(Node *root)
{
    if (!root)
        return NULL;
    if (!root->left)
        return root;
    return getMinNode(root->left);
}
Node *deleteNode(Node *root, int data)
{
    if (!root)
        return NULL;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        else if (!root->right)
        {
            Node *tmp = root->left;
            delete root;
            return tmp;
        }
        else if (!root->left)
        {
            Node *tmp = root->right;
            delete root;
            return tmp;
        }
        else
        {
            Node *tmp = getMinNode(root->right);
            root->data = tmp->data;
            root->right = deleteNode(root->right, tmp->data);
        }
    }
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1)
    {
        int l = getBalance(root->left);
        if (l >= 0)
        {
            return rightRotation(root);
        }
        else
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }
    else if (balance < -1)
    {
        int r = getBalance(root->right);
        if (r <= 0)
        {
            return leftRotation(root);
        }
        else
        {
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
    root = insertToAVL(root, 1);
    root = insertToAVL(root, 2);
    root = insertToAVL(root, 3);
    root = insertToAVL(root, 4);
    root = insertToAVL(root, 5);
    root = insertToAVL(root, 6);

    bfs(root);
    return 0;
}