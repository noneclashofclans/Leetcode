class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>> ans;
       if (root == NULL) return ans;
       queue<TreeNode*> q;
       q.push(root);

       while (q.size() > 0){
        int n = q.size();
        vector<int> v;
        for (int i = 0; i < n; i++){
            TreeNode* n = q.front();
            q.pop();
            if (n->left!= NULL) q.push(n->left);
            if (n->right!= NULL) q.push(n->right);
            v.push_back(n->val);
        }
        ans.push_back(v);
       }
       return ans;
    }
};