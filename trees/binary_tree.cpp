#include<iostream>
#include<queue>
#include<stack>

using std::cout;
using std::cin;
using std::endl;
using std::queue;
using std::stack;

class node{
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this -> data = d;
        this -> left = nullptr;
        this -> right = nullptr;
    }   
};

node* buildBTree(node* root){
    int data;
    cout << "Enter Data: " << endl;
    cin >> data;
    root = new node(data);

    if (data == -1)
        return nullptr;

    cout << "Enter data to insert to the left of " << data << endl;
    root -> left = buildBTree(root -> left);
    cout << "Enter data to insert to the right of " << data << endl;
    root -> right = buildBTree(root -> right);

    return root;
}

void levelOrderTraversal(node* root){
    cout << "\nLevel Order Traversal \n";

    queue<node*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        cout << q.front()->data << " ";
        if (q.front()->left)
            q.push(q.front()->left);
        
        if (q.front()->right)
            q.push(q.front()->right);

        q.pop();

        if (q.front() == nullptr){
            cout << endl;
            q.pop();
            if (!q.empty())
                q.push(nullptr);
        }   
    }
}

void ReverseLevelOrder(node* root){

    cout << "\nReverse Level Order Traversal \n";

    stack<node*> st;
    queue<node*> q;

    q.push(root);
    q.push(nullptr);

    while(!q.empty()){

        st.push(q.front());

        if (q.front()->left)
            q.push(q.front() -> left);
        
        if (q.front()->right)
            q.push(q.front() -> right);
        
        q.pop();

        if (q.front() == nullptr){
            q.pop();
            st.push(nullptr);
            if (!q.empty())
                q.push(nullptr);
        }
    }

    while(!st.empty()){
        if (st.top() == nullptr)
            cout << endl;
    
        else
            cout << st.top() -> data << " "; 

        st.pop();
    }   
}

void inorderTraversal(node* root){
    if (root == nullptr)
        return;

    inorderTraversal(root -> left);
    cout << root -> data << " ";

    inorderTraversal(root -> right);
}

void preOrderTraversal(node* root){
    if (root == nullptr)
        return;

    cout << root-> data << " ";

    preOrderTraversal(root -> left);
    preOrderTraversal(root -> right);
}

void postOrderTraversal(node* root){
    if (root == nullptr)
        return;

    postOrderTraversal(root -> left);
    postOrderTraversal(root -> right);

    cout << root-> data << " ";
}

void buildLevelOrder(node* &root){
    int data;
    cout << "Enter data for root: " << endl;
    cin >> data;
    root = new node(data);

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << "Enter data to insert to the left of " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1){
            temp -> left = new node(leftData);
            q.push(temp -> left); 
        }

        cout << "Enter data to insert to the right of " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1){
            temp -> right = new node(rightData);
            q.push(temp -> right);
        }
    }
}


int main(){

    node* root = nullptr;
    /*
    root = buildBTree(root);

    //input 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

    //input 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "\nInorder Traversal: ";
    inorderTraversal(root);

    cout << "\nPreorder Traversal: ";
    preOrderTraversal(root);
    
    cout << "\nPostorder Traversal: ";
    postOrderTraversal(root);

    // ReverseLevelOrder(root);
    */
    
    buildLevelOrder(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1  

    levelOrderTraversal(root);

    return 0;
}