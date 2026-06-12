#include <bits/stdc++.h>
using namespace std;

// define tree node structure
struct TreeNode {
    // value of the node
    int val;
    // pointer to the left child
    TreeNode* left;
    // pointer to the right child
    TreeNode* right;
    // constructor
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// solution class
class Solution {
public:
    // find inorder successor by building inorder list and binary searching
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        // container for inorder traversal
        vector<int> inorder;
        // fill inorder list
        inorderTraversal(root, inorder);
        // locate index of p->val (or insertion index)
        int idx = binarySearch(inorder, p->val);
        // handle edge cases: last element or invalid
        if (idx == (int)inorder.size() - 1 || idx == -1) {
            return nullptr;
        }
        // return a new node with successor value (mirroring given logic)
        return new TreeNode(inorder[idx + 1]);
    }

    // inorder traversal helper
    void inorderTraversal(TreeNode* root, vector<int>& inorder) {
        // base case
        if (root == nullptr) return;
        // traverse left
        inorderTraversal(root->left, inorder);
        // visit node
        inorder.push_back(root->val);
        // traverse right
        inorderTraversal(root->right, inorder);
    }

    // binary search helper
    int binarySearch(vector<int>& arr, int target) {
        // search bounds
        int left = 0, right = (int)arr.size() - 1;
        // standard binary search
        while (left <= right) {
            // midpoint
            int mid = left + (right - left) / 2;
            // found case
            if (arr[mid] == target) return mid;
            // move right
            else if (arr[mid] < target) left = mid + 1;
            // move left
            else right = mid - 1;
        }
        // not found: return insertion index or -1 if at end
        return left == (int)arr.size() ? -1 : left;
    }
};

// inorder print helper
void printInOrder(TreeNode* root) {
    // base case
    if (root == nullptr) return;
    // left
    printInOrder(root->left);
    // node
    cout << root->val << " ";
    // right
    printInOrder(root->right);
}

// program entry
int main() {
    // construct BST
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    // show BST inorder
    cout << "BST: ";
    printInOrder(root);
    cout << endl;

    // pick node p (value 4)
    TreeNode* p = root->left->right;

    // compute successor
    Solution solution;
    TreeNode* successor = solution.inorderSuccessor(root, p);

    // print result
    if (successor != nullptr) {
        cout << "Inorder Successor of " << p->val << " is: " << successor->val << endl;
    } else {
        cout << "Inorder Successor of " << p->val << " does not exist." << endl;
    }

    // done
    return 0;
}
