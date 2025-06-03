class Solution {
public:
    void reverseNodesDFS(TreeNode* left, TreeNode* right, int level){
        if (!left || !right) return;

        if (level % 2 == 1){
            // an odd level
            swap(left->val, right->val);
        }
        // Mirror condition in a perfect BT
        reverseNodesDFS(left->left, right->right, level + 1);
        reverseNodesDFS(left->right, right->left, level + 1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr;
        reverseNodesDFS(root->left, root->right, 1);
        return root;
    }
};