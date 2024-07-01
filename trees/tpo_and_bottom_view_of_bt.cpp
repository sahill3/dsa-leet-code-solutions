#include <iostream>
#include <vector>
#include <queue>
#include <map>

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

vector<int> bottomView(Node* root) {
    vector<int> ans;
    
    if (root == nullptr)
        return ans;
        
    queue<pair<Node*, int>> q;
    map<int, int> bottomNodes;
    
    q.push(make_pair(root, 0));
    
    while (!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();
        
        Node* frontNode = temp.first;
        int hd = temp.second;
        
        bottomNodes[hd] = frontNode->data;
        
        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd - 1));
        
        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd + 1));
    }
    
    for (auto i : bottomNodes)
        ans.push_back(i.second);
        
    return ans;
}

vector<int> topView(Node *root){
    
    vector<int> ans;
    
    if (root == nullptr)
        return ans; 

    
    map<int, int> topNode;
    
    queue<pair<Node*, int>> q;
    
    q.push(make_pair(root, 0));
    
    while (!q.empty()){
        pair <Node* ,int> temp = q.front();
        q.pop();
        
        Node* frontNode = temp.first;
        
        int hd = temp.second;
        
        if (topNode.find(hd) == topNode.end())
            topNode[hd] = frontNode -> data;
            
            
        if (frontNode -> left)
            q.push(make_pair(frontNode -> left, hd - 1));
            
        if (frontNode -> right)
            q.push(make_pair(frontNode -> right, hd + 1));
        
    }   
    
    for (auto i: topNode)
        ans.push_back(i.second);
    
    return ans;
}

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

int main() {
    Node* root = buildBTree();

    vector<int> bottom_view = bottomView(root);
    vector<int> top_view = topView(root);

    cout << "\nBottom view of the tree: ";
    for (int val : bottom_view) 
        cout << val << " ";
    
    cout << endl;

    cout << "\nTop view of the tree: ";
    for (int val : top_view) 
        cout << val << " ";
    
    cout << endl;

    //input: 10 20 40 -1 -1 50 -1 -1 30 60 -1 -1 70 -1 -1

    /*
                10
               /   \
              20    30
             /  \  /  \
            40  50/    70
                60  
    */

    return 0;
}
