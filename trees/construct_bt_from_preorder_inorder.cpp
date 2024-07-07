#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

    TreeNode(int d){
        this -> val = d;
        this -> left = nullptr;
        this -> right = nullptr;
    }
};

void findPosition(vector<int> inorder, map<int,int> &map, int n){
    for (int i = 0; i<n; i++){
        map[inorder[i]] = i;   
    }
}

TreeNode* constructFromInPre(vector<int> preorder, vector<int> inorder, int &index, int inorderStart, int inorderEnd, map<int,int> nodeToIndex, int n){

    if (index >= n || inorderStart > inorderEnd)
        return nullptr;

    int element = preorder[index++];

    int posi = nodeToIndex[element];

    TreeNode* root = new TreeNode(element);

    root -> left = constructFromInPre(preorder, inorder, index, inorderStart, posi - 1, nodeToIndex, n);
    root -> right = constructFromInPre(preorder, inorder, index, posi+1, inorderEnd, nodeToIndex, n);

    return root;
}

void levelOrderTraversal(TreeNode* root){
    cout << "Level Order Traversal - \n";
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        TreeNode* temp = q.front();
        cout << temp->val << " ";
        q.pop();

        if (temp -> left)
            q.push(temp -> left);

        if (temp -> right)
            q.push(temp -> right);

        if (q.front() == nullptr){
            cout << endl;
            q.pop();
            if (!q.empty())
                q.push(nullptr); 
        }
    }
}

void inorderprint(TreeNode* root){
    if (root == nullptr)
        return;

    inorderprint(root -> left);
    cout << root->val << " ";
    inorderprint(root -> right);
}

int main(){

    vector<int> preorder {3,9,20,15,7};
    vector<int> inorder {9,3,15,20,7};
    int n = preorder.size();
    int index = 0;

    map<int, int> nodeToIndex;
    
    findPosition(inorder, nodeToIndex, n);

    TreeNode* root = constructFromInPre(preorder, inorder, index, 0, n-1, nodeToIndex, n);

    levelOrderTraversal(root);
    // inorderprint(root);
    
    return 0;
}