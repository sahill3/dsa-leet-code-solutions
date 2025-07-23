#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            this->data = val;
            this -> left = nullptr;
            this -> right  = nullptr;
        }
};

void levelOrderTraversal(Node* root){
    queue<Node*> q;

    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if (temp == nullptr){
            cout << "\n";
            if (!q.empty()) q.push(NULL);
        }

        else{
            cout << temp -> data << " ";
            if (temp -> left) q.push(temp->left);
            if (temp -> right) q.push(temp->right);
        }
    }
}

Node* insertIntoBST(Node* &root, int data){
    if (root == nullptr){
        root = new Node(data);
        return root;
    }

    if (data < root -> data)
        root -> left = insertIntoBST(root->left, data);
    else
        root -> right = insertIntoBST(root->right, data);

    return root;
}

void takeInput(Node* &root){
    int data;
    cin >> data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

int main(){

    Node* root = nullptr;

    takeInput(root);

    cout << "Printing";
    levelOrderTraversal(root);

    return 0;
}