class Solution {
public:
    void reverseNodesBydfs(TreeNode* left_node,TreeNode* right_node, int level){
        if (!left_node || !right_node) return;

        if (level % 2 == 1){
            int temp = left_node->val;
            left_node->val = right_node->val;
            right_node->val = temp;
        }

        reverseNodesBydfs(left_node->left,right_node->right, level+1);
        reverseNodesBydfs(left_node->right,right_node->left, level+1);

    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr;

        reverseNodesBydfs(root->left,root->right, 1);
        return root;
    }
};