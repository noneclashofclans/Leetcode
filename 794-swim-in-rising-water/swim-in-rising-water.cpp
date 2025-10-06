class Solution {
public:
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> visited(n, vector<int>(n, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

        pq.push({grid[0][0], 0, 0});
        
        visited[0][0] = 1;
        int ans = 0;

        while (!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int t = curr[0], x = curr[1], y = curr[2];

            ans = max(ans, t);

            if (x == n-1 && y == n-1) return ans;

            for (auto &d : dir) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    pq.push({grid[nx][ny], nx, ny});
                }
            }
        }

        return ans;
    }
};