class Solution {
public:
    bool solve(string& s, string& p, int i, int j, vector<vector<int>>& memo) {
        int n = s.size(), m = p.size();
        
       
        if (j == m) {
            return i == n;
        }
        
        
        if (memo[i][j] != 0) {
            return memo[i][j] == 1;
        }
        
        bool result = false;
        
        if (p[j] == '*') {
            
            result = solve(s, p, i, j + 1, memo);
            
            if (!result && i < n) {
                result = solve(s, p, i + 1, j, memo);
            }
        } else {
            
            if (i < n && (s[i] == p[j] || p[j] == '?')) {
                result = solve(s, p, i + 1, j + 1, memo);
            }
            
        }
        
        memo[i][j] = result ? 1 : -1;
        return result;
    }
    
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, 0));
        return solve(s, p, 0, 0, memo);
    }
};