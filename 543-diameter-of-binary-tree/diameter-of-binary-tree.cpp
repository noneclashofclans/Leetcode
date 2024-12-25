/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxD = 0;
    int levels(TreeNode* root){
        if (!root) return 0;
        int ll = levels(root->left);
        int rl = levels(root->right);
        int max_depth = max(ll,rl);
        int maxi = 1 + max_depth;
        return maxi;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int dia = levels(root->left) + levels(root->right);
        maxD = max(dia,maxD);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxD;
    }
};