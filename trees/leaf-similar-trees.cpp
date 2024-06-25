#include<iostream>
#include<vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

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

void solve(TreeNode* root, vector<int> &vec){
    if (root == nullptr)
        return;

    solve(root->left, vec);
    
    if (!root->left && !root->right)
        vec.push_back(root->val);

    solve(root->right, vec);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> v1;
    vector<int> v2;

    solve(root1, v1);
    solve(root2, v2);

    if (v1.size() != v2.size())
        return false;

    for (int i = 0; i < v1.size(); i++){
        if (v1[i] != v2[i])
            return false;
    }
    
    return true;
}

TreeNode* buildTree(TreeNode* root){

    int data;
    cout << "Enter data: " << endl;
    cin >> data;
    root = new TreeNode(data);

    if (data == -1)
        return nullptr;

    cout << "Enter data to be inserted to the left of " << root -> val << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter data to be inserted to the right of " << root -> val << endl;
    root -> right = buildTree(root -> right);

    return root;
}

int main(){
    
    TreeNode* root1;
    TreeNode* root2;

    root1 = buildTree(root1);
    root2 = buildTree(root2);

    if (leafSimilar(root1, root2))
        cout << "Trees have identical Leaves.";
    else
        cout << "Trees do not have identical Leaves.";
    
    return 0;
}

// TCs
// 3 5 6 -1 -1 2 7 -1 -1 4 -1 -1 1 9 -1 -1 8 -1 -1
// 3 5 6 -1 -1 7 -1 -1 1 4 -1 -1 2 9 -1 -1 8 -1 -1

// 1 2 -1 -1 3 -1 -1
// 1 3 -1 -1 2 -1 -1