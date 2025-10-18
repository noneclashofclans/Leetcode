class Solution {
public:
    vector<int> ans;
    void solve(Node* root){
        if (!root) return;
        for (Node* child : root->children){
            solve(child);
        }
        ans.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        // left = 2*i + 1
        // right = 2*i + 2
        // each step separated by null

        // left->right->root
        
        solve(root);
        return ans;

    }   
};