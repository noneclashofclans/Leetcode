class Solution {
public:
    void recoverTree(TreeNode* root) {
        // inorder traversal by stack
        vector<TreeNode*> inorder;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr || !st.empty()){
            while (curr){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            inorder.push_back(curr);
            curr = curr->right;
        }
        int n = inorder.size();
        TreeNode* x = nullptr, *y = nullptr;

        for (int i = 0; i < n-1; i++){
            if (inorder[i]->val > inorder[i+1]->val){
                if (!x) x = inorder[i];
                y = inorder[i+1];
            }
        }
        if (x && y) swap(x->val, y->val);
    }
};