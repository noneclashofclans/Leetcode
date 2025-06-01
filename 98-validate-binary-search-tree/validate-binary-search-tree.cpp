class Solution {
public:
    bool helper(TreeNode* root, long long lo, long long hi){
        if (!root) return true;
        if (root->val >= hi || root->val <= lo) return false;

        return helper(root->left, lo, root->val) && helper(root->right, root->val, hi);
    }
    bool isValidBST(TreeNode* root) {
        if (!root) return false;

        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};