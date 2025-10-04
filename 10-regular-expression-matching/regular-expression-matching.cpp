class Solution {
public:
    bool solve(string& s, string& p, int i, int j){

        if (j == p.size()) return i == s.size();
        bool hasStar = (j + 1 < p.size() && p[j + 1] == '*');

        if (hasStar){
            return solve(s, p, i, j + 2) || 
            (i < s.size() && (s[i] == p[j] || p[j] == '.') && solve(s, p, i + 1, j));

        }
        else {
            if (i < s.size() && (s[i] == p[j] || p[j] == '.')) {
                return solve(s, p, i + 1, j + 1);
            }
            return false;
        }
    }
    bool isMatch(string s, string p) {
        return solve(s, p, 0, 0);
    }
};