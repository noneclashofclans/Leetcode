class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // brute force
        int n = mat.size();


        // [[1,1,0,0,0],  // 2
        // [1,1,1,1,0],   // 4
        // [1,0,0,0,0],     // 1
        // [1,1,0,0,0],     // 2
        // [1,1,1,1,1]]     // 5
        vector<pair<int,int>> sols;

        for(int i = 0; i < n; i++){
            int soldiers = 0;

            for(auto c : mat[i]){
                if (c == 1) soldiers++;
            }

            sols.push_back({soldiers, i});
        }

        // sols: 2, 4, 1, 2, 5
        sort(sols.begin(), sols.end());

        // sols: 1, 2, 2, 4, 5

        vector<int> ans;
        for(int i = 0; i < k;i++){
            ans.push_back(sols[i].second);
        }

        return ans;
    }
};