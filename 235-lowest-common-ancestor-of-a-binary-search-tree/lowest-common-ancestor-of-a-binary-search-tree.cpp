class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int small = min(p->val, q->val);
        int large = max(p->val , q->val);

        while (root != NULL){
            if (root->val < small){
                root = root->right; // p and q belong to the right subtree
            }
            else if ( root-> val > large) root = root->left;

            else return root;
        }
        return nullptr;
    }
};