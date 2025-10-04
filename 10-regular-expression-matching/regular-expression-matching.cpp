class Solution {
public:
    bool solve(string& s, string& p, int i, int j, vector<vector<int>>& dp){
        if (dp[i][j] != -1) return dp[i][j];

        if (j == p.size()) return dp[i][j] = (i == s.size());
        bool hasStar = (j + 1 < p.size() && p[j + 1] == '*');

        if (hasStar){
            bool skip_the_star = solve(s, p, i, j + 2, dp); 
            bool use_the_star = (i < s.size() && (s[i] == p[j] || p[j] == '.') && solve(s, p, i + 1, j, dp));
            dp[i][j] = (use_the_star || skip_the_star);
            return dp[i][j];
        }
        else {
            if (i < s.size() && (s[i] == p[j] || p[j] == '.')) {
                return dp[i][j] = solve(s, p, i + 1, j + 1, dp);
            }
            return dp[i][j] = false;
        }
    }
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(s, p, 0, 0, dp);
    }
};