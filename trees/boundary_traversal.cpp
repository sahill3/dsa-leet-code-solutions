#include<iostream>
using std::cout;
using std::cin;
using std::endl;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d){
        this -> data = d;
        this -> left = nullptr;
        this -> right = nullptr;
    }
};

void leftBorder(Node* root){
    if (!root || (root -> left == nullptr && root -> right == nullptr))
        return;
    
    cout << root -> data << " ";
    if (root -> left)
        leftBorder(root -> left);
    else    
        leftBorder(root -> right);
}

void leafNodes(Node* root){
    if (root == nullptr)
        return;
    
    if (root -> left == nullptr && root -> right == nullptr){
        cout << root -> data << " ";
        return;
    }
    
    leafNodes(root -> left);
    leafNodes(root -> right);
}

void rightBorder(Node* root){
    if (!root || (root -> left == nullptr && root -> right == nullptr))
        return;
    
    if (root -> right)
        rightBorder(root -> right);
    else
        rightBorder(root -> left);
    
    cout << root -> data << " ";
}

void boundaryTraversal(Node* root){
    if (root == nullptr)
        return;

    cout << "Left Border: " << endl;
    cout << root -> data << " ";
    leftBorder(root -> left);
    cout << "\nLeaf Nodes: " << endl;
    leafNodes(root->left);
    leafNodes(root->right);
    cout << "\nRight Border: " << endl;
    rightBorder(root->right);
}

Node* buildTree(Node* root){
    int data;
    cout << "Enter data: " << endl;
    cin >> data;
    root = new Node(data);

    if (data == -1)
        return nullptr;
    
    cout << "Enter the data to insert to the left of " << data << endl;
    root -> left = buildTree(root -> left);
    
    cout << "Enter the data to insert to the right of " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

int main(){
    
    Node* root;

    root = buildTree(root);

    boundaryTraversal(root);

    // 1 2 3 -1 -1 5 6 -1 -1 8 -1 -1 4 -1 7 -1 9 10 -1 -1 11 -1 -1
    return 0;
}