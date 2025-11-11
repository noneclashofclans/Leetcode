class Solution {
public:
    int solve(int i, vector<string>& strs, int m, int n, int sz, vector<vector<vector<int>>>& dp){
        if (i == sz) return 0;

        if (dp[i][m][n] != -1) return dp[i][m][n];

        int cnto = 0, cnta = 0;
        
        for (char c : strs[i]){
            if (c == '0') cnto++;
            else cnta++;
        }

        int skip = solve(i + 1, strs, m, n, sz, dp);

        int take = 0;

        if (cnto <= m && cnta <= n){
            take = 1 + solve (i + 1, strs, m - cnto, n - cnta, sz, dp);
        }

        return dp[i][m][n] =  max (take, skip);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();

        vector<vector<vector<int>>> dp(sz + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

        return solve (0, strs, m, n, sz, dp);
    }
};