class Solution {
public:
    pair<int,int> max_value_in_nums (vector<int>& nums){
        int maxx = INT_MIN;
        int maxx_idx = -1;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > maxx){
                maxx = nums[i];
                maxx_idx = i;
            }
        }
        return {maxx,maxx_idx};
    }
    TreeNode* build_tree(vector<int>& nums){
        int n = nums.size();
        pair<int,int> res = max_value_in_nums(nums);
        int maxValue = res.first;
        int maxValue_idx = res.second;

        TreeNode* root = new TreeNode(maxValue);
        
        if (maxValue_idx > 0) {
        vector<int> left(nums.begin(), nums.begin() + maxValue_idx);
        root->left = build_tree(left);
        } else {
            root->left = nullptr;
        }

        if (maxValue_idx + 1 < nums.size()) {
            vector<int> right(nums.begin() + maxValue_idx + 1, nums.end());
            root->right = build_tree(right);
        } else {
            root->right = nullptr;
        }

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return nullptr;
        TreeNode* node = build_tree(nums);

        return node;

    }
};