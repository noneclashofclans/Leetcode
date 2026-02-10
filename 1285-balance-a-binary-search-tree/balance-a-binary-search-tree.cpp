class Solution {
public:    
    TreeNode* make_new_tree(vector<int> &arr, int left, int right){
        if (left > right) return nullptr;
        int mid = left + (right - left)/2;

        TreeNode* newNode = new TreeNode(arr[mid]);

        // recursively making the tree from left to mid-1
        newNode->left = make_new_tree(arr, left, mid-1);
        // doing the rest here 
        newNode->right = make_new_tree(arr, mid+1, right);

        return newNode;
    }
    void inorder(TreeNode* root, vector<int>& arr){
        if (!root) return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        return make_new_tree(arr, 0, arr.size() - 1);
    }
};