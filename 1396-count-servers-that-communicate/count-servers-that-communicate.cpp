class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        vector<int> row_servers(n, 0);
        vector<int> col_servers(m, 0);
        
        for(int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1){
                    row_servers[i]++;
                    col_servers[j]++;
                }
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1){
                    if (row_servers[i] > 1 || col_servers[j] > 1) count++;
                }
            }
        }

        return count;
    }
};