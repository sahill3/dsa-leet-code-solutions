#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<utility>

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

vector<int> verticalOrder(Node *root){
    map<int, map<int, vector<int>>> nodes;
    
    queue<pair<Node*, pair<int, int>>> q;
    
    vector<int> ans;
    
    if (root == nullptr)
        return ans;
        
    q.push(make_pair(root, make_pair(0, 9)));
    
    while (!q.empty()){
        pair<Node*, pair<int, int>> temp = q.front();
        q.pop();
        
        Node* frontNode = temp.first;
        
        int hd = temp.second.first;
        int level = temp.second.second;
        
        nodes[hd][level].push_back(frontNode -> data);
        
        if (frontNode -> left)
            q.push(make_pair(frontNode -> left, make_pair(hd-1, level+1)));
        
        if (frontNode -> right)
            q.push(make_pair(frontNode -> right, make_pair(hd+1, level+1)));
        
    }
    
    for (auto i : nodes){
        for (auto j : i.second){
            for (auto k : j.second)
            ans.push_back(k);
        }
    }
    return ans;
}

Node* buildTree(Node* root){
    int data;
    cout << "Enter data:" << endl;
    cin >> data;
    root = new Node(data);
    
    if (data == -1)
        return nullptr;

    cout << "Enter data to insert to the left of " << data << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter data to insert to the right of " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

void inorder(Node* root){
    if (root == nullptr)
        return;

    inorder(root -> left);
    cout << root -> data;
    inorder(root -> right);
}

int main(){

    Node* root = nullptr;

    root = buildTree(root);

    vector<int> ans = verticalOrder(root);

    for (int i: ans)
        cout << i << " ";
    
    return 0;
}