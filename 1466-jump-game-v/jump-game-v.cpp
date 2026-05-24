class Solution {
public:

    int solve(int i, int n, vector<int>& arr, int d, vector<int>& dp){
        int maxVisits = 1;
        if (dp[i] != -1) return dp[i];

        for (int j=i+1; j <= min(i+d, n-1); j++){
            if (arr[i] <= arr[j]) break;

            maxVisits = max(maxVisits, 1 + solve(j, n, arr, d, dp));
        }


        for (int j = i-1; j >= max(0, i-d); j--){
            if (arr[i] <= arr[j]) break;
            maxVisits = max(maxVisits, 1 + solve(j, n, arr, d, dp));
        }

        return dp[i] = maxVisits;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();

       int ans = 1;

        vector<int> dp(n, -1);

        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(i, n, arr, d, dp));
        }

        return ans;

    }
};