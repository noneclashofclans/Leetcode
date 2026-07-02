class Solution {
public:
    bool isPossible(vector<vector<int>>& grid,int health){
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> best(m, vector<int>(n, -1));

        int start_health = health - grid[0][0];
        if (start_health < 0) return false;

        q.push({0,0});
        best[0][0] = start_health;


        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int x = top.first;
            int y = top.second;
            if (x == m-1 && y == n-1) return true;
            for(int k = 0; k < 4; k++){
                int nx = x+dx[k];
                int ny = y+dy[k];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n){
                    int newHealth = best[x][y]-grid[nx][ny];
                    if (newHealth > 0 && newHealth > best[nx][ny]){
                        best[nx][ny] = newHealth;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return false;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        return isPossible(grid,health);
    }
};