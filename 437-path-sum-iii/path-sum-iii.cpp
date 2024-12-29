class Solution {
public:
    int pathSum2(TreeNode* root, long long targetSum){
        if(root == NULL){return 0;}
        int count = 0;
        if (root->val == targetSum){count =1;}
        count += pathSum2(root->left,targetSum-root->val);
        count+= pathSum2(root->right,targetSum-root->val);

        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
      if(root==NULL) return 0;
      return pathSum(root->left,targetSum)+pathSum(root->right,targetSum)
      +pathSum2(root,(long long)targetSum);
    }
};