class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return nullptr;

    // If the current node's value is less than low, skip left subtree
    if (root->val < low) {
        return trimBST(root->right, low, high);
    }
    // If the current node's value is greater than high, skip right subtree
    if (root->val > high) {
        return trimBST(root->left, low, high);
    }

    // Otherwise, recursively trim both subtrees
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);

    return root;
    }
};