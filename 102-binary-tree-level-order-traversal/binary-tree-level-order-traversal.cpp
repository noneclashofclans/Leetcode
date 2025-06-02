class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        // edge case
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            int levelSize = q.size();
            vector<int> temp;
            while(levelSize--){
                TreeNode* node = q.front();
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                temp.push_back(node->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};