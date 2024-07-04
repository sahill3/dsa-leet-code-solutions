#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* buildTree(Node* root) {
    int data;
    cout << "Enter data: " << endl;
    cin >> data;
    if (data == -1)
        return nullptr;

    root = new Node(data);
    cout << "Enter the data to insert to the left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data to insert to the right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void kth(Node* root, int k, int node, vector<int>& ans, int& a) {
    if (root == nullptr)
        return;

    if (root->data == node)
        a = k > ans.size() ? -1 : ans[ans.size() - k];

    ans.push_back(root->data);

    kth(root->left, k, node, ans, a);
    kth(root->right, k, node, ans, a);

    ans.pop_back(); 
}

int kthAncestor(Node* root, int k, int node) {
    int a = -1;
    vector<int> ans;
    kth(root, k, node, ans, a);
    return a;
}

/* OPTIMAL 
Node* kth(Node* root, int &k, int node){
    if (root == nullptr)
        return nullptr;
        
    if (root -> data == node)
        return root;
        
    Node* leftAns = kth(root -> left, k, node);
    Node* rightAns = kth(root -> right, k, node);
    
    if (leftAns && !rightAns){
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    
    if (!leftAns && rightAns){
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return nullptr;
}

int kthAncestor(Node *root, int k, int node)
{
    Node* ans = kth(root, k, node);
    
    if (!ans || ans -> data == node)    
        return -1;
    else 
        return ans -> data;
}

*/

int main() {
    Node* root = nullptr;
    root = buildTree(root);

    // cout << "Inorder Traversal of the Tree: " << endl;
    // inorderTraversal(root);
    // cout << endl;

    int k, node;
    cout << "Enter the value of k: ";
    cin >> k;
    cout << "Enter the node value to find kth ancestor of: ";
    cin >> node;

    int ancestor = kthAncestor(root, k, node);
    if (ancestor != -1)
        cout << k << "th ancestor of node " << node << " is " << ancestor << endl;
    else
        cout << k << "th ancestor of node " << node << " does not exist" << endl;


    // 1 2 4 -1 -1 5 -1 -1 3 -1 -1
    return 0;
}
