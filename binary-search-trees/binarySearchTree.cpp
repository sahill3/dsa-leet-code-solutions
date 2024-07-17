#include<iostream>
using namespace std;

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

Node* insertIntoBst(Node* root, int data){
    if (root == nullptr){
        root = new Node(data);
        return root;
    }

    if (data > root -> data)
        root -> right = insertIntoBst(root -> right, data);
    else    
        root -> left = insertIntoBst(root -> left, data); 

    return root;
}

Node* minVal(Node* root){
    Node* temp = root;

    if (!temp)
        return nullptr;

    while(temp -> left != nullptr)
        temp = temp -> left;

    return temp;
}

Node* maxVal(Node* root){
    Node* temp = root;
    
    if (!temp)
        return nullptr;

    while(temp -> right != nullptr)
        temp = temp -> right;

    return temp;
}

void takeinput(Node* &root){
    int data;
    cin >> data;
    
    while(data != -1){
        root = insertIntoBst(root, data);
        cin >> data;
    }
}


void printInorder(Node* root){
    if (root == nullptr)
        return;

    printInorder(root -> left);
    cout << root -> data << " ";
    printInorder(root -> right);
}

int main(){
    

    Node* root = nullptr;

    cout << "Enter the data: ";
    takeinput(root);

    cout << "Printing the BST: "; 
    printInorder(root);
    cout << endl;

    Node* temp = minVal(root);
    cout << temp -> data << endl;

    temp = maxVal(root);
    cout << temp -> data << endl;

    // 10 8 21 7 27 5 4 3 -1

    return 0;
}