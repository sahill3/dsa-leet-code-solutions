#include <iostream>
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

void morrisTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;

    TreeNode *pre = nullptr;
    TreeNode *curr = nullptr;

    curr = root;

    while (curr)
    {
        if (curr->left == nullptr)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {

            pre = curr->left;
            while (pre->right != nullptr && pre->right != curr)
                pre = pre->right;


            if (pre->right == nullptr)
            {
                pre->right = curr;
                curr = curr->left;
            }
            else
            {
                pre -> right = nullptr;
                cout << curr -> data << " ";
                curr = curr -> right;
            }
        }
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root -> right = new TreeNode(3);
    root -> right -> left = new TreeNode(5);
    morrisTraversal(root);
    return 0;
}