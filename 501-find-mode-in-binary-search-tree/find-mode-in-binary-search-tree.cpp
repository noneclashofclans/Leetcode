class Solution {
public:

    void countNodes(TreeNode* root, unordered_map<int,int>& freq){
        if (!root) return;

        freq[root->val]++;

        countNodes(root->left, freq);
        countNodes(root->right, freq);
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> freq;

        if (!root) return {};

        countNodes(root, freq);

        int ans = 0;
        vector<int> anss;

        for (auto x : freq){
            ans = max(ans, x.second);
        }

        for (auto x : freq){
            if (x.second == ans){
                anss.push_back(x.first);
            }
        }
        
        return anss;
    }
};