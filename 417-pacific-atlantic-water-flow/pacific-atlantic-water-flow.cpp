class Solution {
public:
    int n, m;
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& vis, int i, int j){
        vis[i][j] = 1;
        for (auto& d : dir){
            int ni = i+d[0];
            int nj = j+d[1];

            if (ni < 0 || nj < 0 || ni >= n || nj >= m || vis[ni][nj]) continue;
            if (heights[ni][nj] >= heights[i][j])
                 dfs(heights, vis, ni, nj);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
         n = heights.size();
         m = heights[0].size();
        vector<vector<int>> ans;

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            dfs(heights, pacific, i, 0);        
            dfs(heights, atlantic, i, m-1);      
        }

        for (int j = 0; j < m; j++) {
            dfs(heights, pacific, 0, j);        
            dfs(heights, atlantic, n-1, j);      
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) 
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};