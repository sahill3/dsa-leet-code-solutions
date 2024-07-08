#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d) {
        this->val = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

TreeNode* buildTree(TreeNode* root) {
    int data;
    cout << "Enter data: " << endl;
    cin >> data;

    if (data == -1)
        return nullptr;

    root = new TreeNode(data);

    cout << "Enter the data to insert to the left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter the data to insert to the right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

TreeNode* helper(TreeNode* root, int start, unordered_map<TreeNode*, TreeNode*>& nodeToParent) {
    TreeNode* result = nullptr;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* frontNode = q.front();
        q.pop();

        if (frontNode->val == start)
            result = frontNode;

        if (frontNode->left) {
            nodeToParent[frontNode->left] = frontNode;
            q.push(frontNode->left);
        }

        if (frontNode->right) {
            nodeToParent[frontNode->right] = frontNode;
            q.push(frontNode->right);
        }
    }
    return result;
}

int burnTree(TreeNode* start, unordered_map<TreeNode*, TreeNode*>& nodeToParent) {
    unordered_map<TreeNode*, bool> visited;
    int ans = 0;

    queue<TreeNode*> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int size = q.size();
        bool flag = false;

        for (int i = 0; i < size; i++) {
            TreeNode* frontNode = q.front();
            q.pop();

            if (frontNode->left && !visited[frontNode->left]) {
                q.push(frontNode->left);
                visited[frontNode->left] = true;
                flag = true;
            }

            if (frontNode->right && !visited[frontNode->right]) {
                q.push(frontNode->right);
                visited[frontNode->right] = true;
                flag = true;
            }

            if (nodeToParent[frontNode] && !visited[nodeToParent[frontNode]]) {
                q.push(nodeToParent[frontNode]);
                visited[nodeToParent[frontNode]] = true;
                flag = true;
            }
        }
        if (flag)
            ans++;
    }
    return ans;
}

int amountOfTime(TreeNode* root, int start) {
    unordered_map<TreeNode*, TreeNode*> nodeToParent;
    nodeToParent[root] = nullptr;

    TreeNode* targetNode = helper(root, start, nodeToParent);

    int ans = burnTree(targetNode, nodeToParent);

    return ans;
}

int main() {
    TreeNode* root = nullptr;
    root = buildTree(root);

    int start;
    cout << "Enter the value of the starting node: " << endl;
    cin >> start;

    int time = amountOfTime(root, start);
    cout << "Time required to burn the tree: " << time << " units" << endl;

    // 1 5 -1 4 9 -1 -1 2 -1 -1 3 10 -1 -1 6 -1 -1
    //3

    return 0;
}
