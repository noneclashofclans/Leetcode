class Solution {
public:
    int count = 0;
    int ans = -1;
    void inorder_traversal(TreeNode* root, int k){
        if (!root || count >= k) return;

        inorder_traversal(root->left, k);

        count++;
        if (count == k) {
            ans = root->val;
            return;
        }

        inorder_traversal(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
       inorder_traversal(root,k);
       return ans;
    }
};