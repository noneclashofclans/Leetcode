#include <vector>
#include <queue>
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root); //push the root 1st inside the queue

        while (q.size() > 0){
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++){
                TreeNode* node = q.front();
                q.pop();

                if (i == levelSize -1) ans.push_back(node->val);
                
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
            }
        }
        return ans;
    }
};