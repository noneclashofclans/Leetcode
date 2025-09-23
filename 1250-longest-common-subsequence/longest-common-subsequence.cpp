class Solution {
public:

    int rec(int i, int j, string& text1, string& text2, vector<vector<int>>& dp) {
       
        if (i == text1.size() || j == text2.size()) {
            return 0;
        }

        if (dp[i][j] != -1) return dp[i][j];
       
        if (text1[i] == text2[j]) {
            dp[i][j] = 1 + rec(i + 1, j + 1, text1, text2, dp);
        } else {
            
            dp[i][j] = max(rec(i + 1, j, text1, text2, dp), rec(i, j + 1, text1, text2, dp));
        }
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return rec(0, 0, text1, text2, dp);
    }
};
