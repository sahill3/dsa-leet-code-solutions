#include<iostream>
#include<vector>
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


void pathSum(TreeNode* root, int k, int &count, vector<int> path){
    if (root == nullptr)
        return;

    path.push_back(root -> data);

    pathSum(root -> left, k, count, path);
    pathSum(root -> right, k, count, path);

    int size = path.size();
    int sum = 0;

    for (int i = size-1; i >= 0; i--){
        sum += path[i];
        if (sum == k)
            count++;
    }
}

int main(){

    vector<int> path;
    int count = 0;

    TreeNode* root = buildTree(root);

    int k;
    cout << "Enter the value for k: ";
    cin >> k;

    pathSum(root, k, count, path);

    cout << "Count: " << count;  

    // k = 8
    // 10 5 3 3 -1 -1 -2 -1 -1 2 -1 1 -1 -1 -3 -1 11 -1 -1

    return 0;
}