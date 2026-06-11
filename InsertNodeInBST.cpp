#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
            return new TreeNode(val);

        TreeNode* node = root;

        while (node) {
            if (val < node->val) {
                if (node->left == nullptr) {
                    node->left = new TreeNode(val);
                    break;
                }
                node = node->left;
            }
            else {
                if (node->right == nullptr) {
                    node->right = new TreeNode(val);
                    break;
                }
                node = node->right;
            }
        }

        return root;
    }
};

void inorder(TreeNode* root) {
    if (!root) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    Solution obj;
    TreeNode* root = nullptr;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = obj.insertIntoBST(root, x);
    }

    cout << "\nBST (Inorder): ";
    inorder(root);

    int val;
    cout << "\nEnter value to insert: ";
    cin >> val;

    root = obj.insertIntoBST(root, val);

    cout << "\nBST after insertion: ";
    inorder(root);

    return 0;
}