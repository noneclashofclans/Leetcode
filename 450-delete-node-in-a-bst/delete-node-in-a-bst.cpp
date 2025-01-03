class Solution {
public:
    bool dfs(TreeNode* root, int key){ //if node present
        if (!root) return false; //no root
        if(root->val == key){
            return true;
        }
        return dfs(root->left,key) || dfs(root->right,key); //check for the left and right subtrees
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return NULL;
        
        bool isPresent = dfs(root,key);

        if(!isPresent) return root; //return the original tree

        // Node deletion logic
        if (root->val == key) {
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* temp = root->right;
        while (temp->left) {
            temp = temp->left;
        }
        
        root->val = temp->val; // Replace value with inorder successor
        root->right = deleteNode(root->right, temp->val); // Delete the inorder successor
    } else if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else {
        root->right = deleteNode(root->right, key);
    }

    return root;
    }
};