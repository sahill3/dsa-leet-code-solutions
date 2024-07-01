#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* buildBTree() {
    int data;
    cout << "Enter Data: " << endl;
    cin >> data;

    if (data == -1)
        return nullptr;

    Node* root = new Node(data);

    cout << "Enter data to insert to the left of " << data << endl;
    root->left = buildBTree();
    cout << "Enter data to insert to the right of " << data << endl;
    root->right = buildBTree();

    return root;
}

void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void leftSideView(Node* root, int level, vector<int> &leftView){
    if (root == nullptr)
        return;
    
    if (leftView.size() == level)
        leftView.push_back(root -> data);
        
    leftSideView(root->left, level+1, leftView);
    leftSideView(root->right, level+1, leftView);
}

void rightSideView(Node* root, int level, vector<int> &rightView){
    if (root == nullptr){
        return;
    }

    if (rightView.size() == level)
        rightView.push_back(root -> data);

    rightSideView(root->right, level+1, rightView);
    rightSideView(root->left, level+1, rightView);
}

int main(){

    Node* root = buildBTree();

    if (root == nullptr)
        return {};

    vector<int> rightView;
    vector<int> leftView;

    rightSideView(root, 0, rightView);
    leftSideView(root, 0, leftView);

    cout << "\nLeft side View: ";
    for (int i: leftView)
        cout << i << " ";

    cout << endl;

    cout << "\nRight side View: ";
    for (int i: rightView)
        cout << i << " "; 

    return 0;
}