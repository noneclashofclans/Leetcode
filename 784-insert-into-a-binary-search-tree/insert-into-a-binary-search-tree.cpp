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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        if (!root) return newNode;

        TreeNode* currentNode = root;

        while (currentNode){
            if (currentNode->val>val && currentNode->left){
                currentNode = currentNode->left;
            }
            else if (currentNode->val<val && currentNode->right){
                currentNode = currentNode->right;
            }
            else if (currentNode->val > val){
                currentNode->left = newNode;
                return root;
            }
            else if (currentNode->val < val){
                currentNode->right=newNode;
                return root;
            }
        }
        return root;
    }
};