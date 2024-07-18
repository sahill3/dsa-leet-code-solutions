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

void inorderPredecesor(Node* root, Node* &pred, int val){
    if (root == nullptr) return;

    if (root -> data == val){

        if (root -> left != nullptr){
            root = root -> left;

            while (root -> right != nullptr)
                root = root -> right;

            pred = root;
        }

        return;
    }  

    if (val < root -> data)
        inorderPredecesor(root -> left, pred, val);
    else{
        pred = root;
        inorderPredecesor(root -> right, pred, val);
    }
}

int main(){

    Node* root = nullptr;

    cout << "Enter the data: ";
    takeinput(root);

    cout << "Printing the BST: "; 
    printInorder(root);
    cout << endl;

    Node* temp = minVal(root);
    cout << "Max Value: " << temp -> data << endl;

    temp = maxVal(root);
    cout << "Min Value: " << temp -> data << endl;

    Node* pred = nullptr;
    inorderPredecesor(root, pred, 30);

    if (pred)
        cout << "Pred: " << pred -> data;

    // 10 8 21 7 27 5 4 3 -1

    // 50 20 70 10 30 90 110 -1

    return 0;
}