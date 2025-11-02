class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // make a raw 2-D matrix
        vector<vector<int>> mat(m, vector<int> (n, 0));
        // in this single matrix, mark all the areas, where guards are present

        for (auto &g : guards) mat[g[0]][g[1]] = 1;
        for (auto &w : walls) mat[w[0]][w[1]] = 2;

        auto watch = [&](int x, int y, int dx, int dy){
            while (x >= 0 && x < m && y >= 0 && y < n && mat[x][y] != 2){
                if (mat[x][y] == 1) break;
                if (mat[x][y] == 0) mat[x][y] = 3;
                x += dx; y += dy;
            }
        };

        for (auto &g : guards){
            int x=g[0], y=g[1];
            watch(x-1,y,-1,0);
            watch(x+1,y,1,0);
            watch(x,y-1,0,-1);
            watch(x,y+1,0,1);
        }

        int ans = 0;
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                if (mat[i][j] == 0) ans++;

        return ans;

    }
};