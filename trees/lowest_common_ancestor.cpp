#include<iostream>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

    TreeNode(int d){
        this -> data = d;
        this -> left = nullptr;
        this -> right = nullptr;
    }
};

TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
    if (root == NULL)
        return NULL;

    if (root->data == p || root->data == q)
        return root;

    TreeNode* leftAns = lowestCommonAncestor(root -> left, p, q);
    TreeNode* rightAns = lowestCommonAncestor(root -> right, p, q);

    if (leftAns && rightAns)
        return root;

    else if (leftAns && !rightAns)
        return leftAns;
    
    else if (!leftAns && rightAns)
        return rightAns;

    else
        return nullptr;
}

TreeNode* buildTree(TreeNode* root){

    int data;
    cout << "Enter data: " << endl;
    cin >> data;

    root = new TreeNode(data);

    if (data == -1)
        return nullptr;

    cout << "Enter the data to insert to the left of " << data << endl;
    root -> left = buildTree(root -> left);
    
    cout << "Enter the data to insert to the right of " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

int main(){

    TreeNode* root = nullptr;

    root = buildTree(root);

    TreeNode* ans = lowestCommonAncestor(root, 6, 8);
    
    cout << "Answer: " << ans->data;

    // 3 5 6 -1 -1 2 7 -1 -1 4 -1 -1 1 0 -1 -1 8 -1 -1

    return 0;
}