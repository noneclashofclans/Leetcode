class Solution {
public:
    int sum = 0;
    void reverseInorder(TreeNode* root) {
        if (!root) return;
        reverseInorder(root->right);
        sum += root->val;
        root->val = sum;
        reverseInorder(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        if (!root) return NULL;
        //since, from the examples, we can see that the sum starts from right, root, left;
        // so move right->root->left
        reverseInorder(root);
        return root;
    }
};