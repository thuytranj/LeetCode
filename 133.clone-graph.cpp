#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};
Node* dfs (Node* node, unordered_map<Node*, Node*> &clone) {
    if (clone.find (node)!=clone.end())
       return clone[node];
    
    Node* copy = new Node(node->val);
    clone [node]=copy;

    for (auto neighbors:node->neighbors) {
        copy->neighbors.push_back(dfs(neighbors, clone));
    }
    
    return copy;
}
Node *cloneGraph(Node *node)
{
    if (node==NULL) return NULL;
    unordered_map<Node*, Node*> clone;
    return dfs(node, clone);
}
int main () {
    return 0;
}