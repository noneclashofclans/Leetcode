class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // create a root->child map
        unordered_map<int, TreeNode*> mapp;
        unordered_set<int> child;

        for(vector<int>&v : descriptions){
            int p = v[0];   
            int c = v[1];
            int isLeft = v[2];

            if (mapp.find(p) == mapp.end()){
                mapp[p] = new TreeNode(p);
            }

            if (mapp.find(c) == mapp.end()){
                mapp[c] = new TreeNode(c);
            }

            if (isLeft){
                mapp[p]->left = mapp[c];
            }
            else{
                mapp[p]->right = mapp[c];
            }

            child.insert(c);
        }

        for (vector<int>& x : descriptions){
            int par = x[0];
            if (child.find(par) == child.end()){
                return mapp[par];
            }
        }

        return NULL;
    }
};