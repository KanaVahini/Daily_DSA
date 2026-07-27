#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    vector<int> ans;

    void postorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        postorder(root->left);
        postorder(root->right);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return ans;
    }
};

TreeNode* buildTree() {
    int val;
    cin >> val;

    if (val == -1)
        return nullptr;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        int leftVal, rightVal;
        cin >> leftVal;

        if (leftVal != -1) {
            current->left = new TreeNode(leftVal);
            q.push(current->left);
        }

        cin >> rightVal;

        if (rightVal != -1) {
            current->right = new TreeNode(rightVal);
            q.push(current->right);
        }
    }

    return root;
}

int main() {
    cout << "Enter tree in level order (-1 for NULL):\n";

    TreeNode* root = buildTree();

    Solution obj;
    vector<int> result = obj.postorderTraversal(root);

    cout << "Postorder Traversal: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}