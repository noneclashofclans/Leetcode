class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int level = q.size();
            for (int i = 0; i < level; i++){
                TreeNode* node = q.front(); q.pop();

                if (i == level - 1) ans.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right); 
            }
        }
        return ans;
    }
};