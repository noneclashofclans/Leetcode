class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return {};

        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()){
            int l = q.size();
            vector<int> ans;
            while (l--){
                TreeNode* node = q.front(); q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                ans.push_back(node->val);
            }
     
            res.push_back(ans);
        }
        return res;
    }
};