class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if (!root) return node;
        
        TreeNode* current = root;

        while (current != NULL){
            if (current->val > val && current->left){
                current = current->left;
            }
            else if (current->val < val && current->right){
                current = current -> right;
            }
            else if (current->val >  val){
                current->left = node;
                return root;
            }
            else if (current->val < val){
                current->right = node;
                return root;
            }
        }
        return root;
    }
};