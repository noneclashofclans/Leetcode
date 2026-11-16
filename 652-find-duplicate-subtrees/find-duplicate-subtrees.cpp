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
    void traverse(TreeNode* root, vector<TreeNode*>& ans){
        // preorder traversal
        if (!root) return;
        ans.push_back(root);
        traverse(root->left, ans);
        traverse(root->right, ans);
    }

    string getStringFormat(TreeNode* node, unordered_map<TreeNode*, string>& memo){
        if (!node) return "#";
        if (memo.count(node)) return memo[node];

        return memo[node] = to_string(node->val) + "," + getStringFormat(node->left, memo) + "," + getStringFormat(node->right, memo);
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // ex-1 arr = {1,2,4,3,2,4,4}
        // ex-2: arr = {2,2,3,2,3}
        vector<TreeNode*> res;
        vector<TreeNode*> ans;

        traverse(root, ans);
        unordered_map<string, int> see;
        unordered_map<TreeNode*, string> memo;

        for (int i = 0; i < ans.size(); i++){
            string seen = getStringFormat(ans[i], memo);

            if (++see[seen] == 2){
                res.push_back(ans[i]);
            }
        }

        return res;
    }
};