class Solution {
public:
    void preorder_traversal(TreeNode* root, vector<int> &ans){
        if(root == NULL)return;
        ans.push_back(root->val);
        preorder_traversal(root->left,ans);
        preorder_traversal(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> ans;
       preorder_traversal(root,ans);
       return ans;
    }
};