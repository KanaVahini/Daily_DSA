#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

TreeNode* buildTree() {
    int val;
    cin >> val;

    if (val == -1)
        return NULL;

    TreeNode* root = new TreeNode(val);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

void levelOrder(TreeNode* root) {
    if (root == NULL)
        return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left)
            q.push(curr->left);

        if (curr->right)
            q.push(curr->right);
    }
}

int main() {
    cout << "Enter the tree: (-1 for NULL): ";

    TreeNode* root = buildTree();

    cout << "Level Order Traversal: ";
    levelOrder(root);

    return 0;
}