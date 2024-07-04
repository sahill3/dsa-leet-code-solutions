#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

pair<int, int> solve(Node* root) {
    if (root == nullptr)
        return make_pair(0, 0);
        
    pair<int, int> leftPair = solve(root->left);
    pair<int, int> rightPair = solve(root->right);
    
    pair<int, int> ans;
    
    ans.first = root->data + leftPair.second + rightPair.second;
    ans.second = max(leftPair.first, leftPair.second) + max(rightPair.first, rightPair.second);
    
    return ans;
}

int getMaxSum(Node *root) {
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}

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

int main() {
    Node* root;

    root = buildTree(root);

    cout << "\nMaximum sum of non-adjacent nodes: " << getMaxSum(root) << endl;
    
    // 1 2 1 -1 -1 -1 3 4 -1 -1 5 -1 -1

    return 0;
}
