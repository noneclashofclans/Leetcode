class Solution {
public:
    int height(TreeNode* root){
        if (!root) return true;

        // int lh = 1 + height(root->left);
        // int rh = 1 + height(root->right);

        // int lh = 0, rh = 0;

        // if (root->left){
        //     lh++;
        //     height(root->left);
        // }
        // else
        //     height(root->right);
        //     rh++;
        // }

        // return abs(lh - rh) <= 1;

        int lh = height(root->left);
        if (lh == -1) return -1;

        int rh = height(root->right);
        if (rh == -1) return -1;

        if (abs(lh - rh) > 1) return -1;

        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        // left height == right height
        return height(root) != -1;
    }
};