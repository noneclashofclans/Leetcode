class Solution {
public:
    int n, m;
    vector<string> s;
    vector<vector<int>> dp;

    bool valid(int prev, int cur) {
        if (prev == -1) return true;
        for (int r = 0; r < n; r++) {
            if (s[r][prev] > s[r][cur])
                return false; // not lexicographic
        }
        return true;
    }

    int solve(int prev, int cur) {
        if (cur == m) return 0;
        int &res = dp[prev + 1][cur];
        if (res != -1) return res;

        res = solve(prev, cur + 1);

        if (valid(prev, cur)) {
            res = max(res, 1 + solve(cur, cur + 1));
        }
        return res;
    }


    int minDeletionSize(vector<string>& strs) {
        s = strs;
        n = s.size();
        m = s[0].size();

        dp.assign(m + 1, vector<int> (m, -1));

        int ans = solve (-1, 0);

        return (m - ans);
    }
};