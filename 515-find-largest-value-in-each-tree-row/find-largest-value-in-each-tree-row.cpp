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
    void largest(TreeNode* root, vector<int>& output, int level){
        if(root == NULL){
            return;
        }
        if (level >= output.size()){
            output.push_back(root->val);
        }else{
             output[level] = max(output[level], root->val);
        }

        largest(root->left,output,level+1);
        largest(root->right,output,level+1);
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> output;
        largest(root,output,0); //'0' level
        return output;
    }
};