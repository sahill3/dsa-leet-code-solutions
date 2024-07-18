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

Node* deleteFromBST(Node* root, int val){
    if (! root)
        return root;

    if (root -> data == val){
        //0 child
        if (!root -> left && !root -> right){
            delete root;
            return nullptr;
        }
        // only left child
        else if(root -> left && !root -> right){
            Node* temp = root -> left;
            delete root;
            return temp;
        }
        // only right child
        else if (!root -> left && root -> right){
            Node* temp = root -> right;
            delete root;
            return temp;
        }
        // both child exist
        else{
            int mini = minVal(root -> right) -> data;
            root -> data = mini;
            
            root -> right = deleteFromBST(root->right, mini);
            return root;
        }

    }
    else if(val < root -> data)
        root -> left = deleteFromBST(root -> left, val);
    else
        root -> right = deleteFromBST(root -> right, val);
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
        cout << "Pred: " << pred -> data << endl;

    // 10 8 21 7 27 5 4 3 -1

    // 50 20 70 10 30 90 110 -1

    root = deleteFromBST(root, 50);

    cout << "Printing the BST: "; 
    printInorder(root);
    cout << endl;

    return 0;
}