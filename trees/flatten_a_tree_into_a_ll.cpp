#include<iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int d)
    {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void inorder(TreeNode *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while(curr){
            if (curr -> left){
                
                TreeNode* prev = curr -> left;

                while(prev -> right)
                    prev = prev -> right;

                prev -> right = curr -> right;
                curr -> right = curr -> left;
                curr -> left = nullptr;
                curr = curr -> right;
            }
            else{
                curr = curr -> right;
            }
        }
    }

int main()
{
    TreeNode *root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(5);

    root -> left -> left = new TreeNode(3);
    root -> left -> right = new TreeNode(4);
    
    root -> right -> right = new TreeNode(6);

    inorder(root);
    cout << endl;

    flatten(root);

    inorder(root);

    return 0;
}