class Solution {
public:
    // vector<int> inorder_traversal(TreeNode* root, vector<int>& arr){
    //     if (!root) return arr;

    //     inorder_traversal(root->left,arr);
    //     arr.push_back(root->val);
    //     inorder_traversal(root->right,arr);

    //     return arr;
    // }
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        // vector<int> arr;
        // vector<int> nums = inorder_traversal(root,arr);

        int rangeSum = 0;
        // for (int i = 0; i < nums.size(); i++){
        //     if (nums[i] >= low && nums[i] <= high) {
        //         rangeSum += nums[i];
        //     }
        // }
        // return rangeSum;

        if (root->val >= low && root->val <= high){
            rangeSum += root->val;
        }

        if (root->val > low){
            rangeSum += rangeSumBST(root->left, low, high);
        }

        if (root->val < high){
            rangeSum += rangeSumBST(root->right, low, high);
        }
        return rangeSum;
    }
};