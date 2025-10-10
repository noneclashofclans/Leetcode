class Solution {
public:
    int solve(vector<int>& energy, int i, int j, int k, vector<int>& dp){ 
        int n = energy.size();
        if (i >= n) return 0;

        if(dp[i] != INT_MIN) return dp[i];

        if (j >= n){
            return dp[i] = energy[i];
        }

        int sum = energy[i] + solve(energy, j, j+k, k, dp);
        dp[i] = sum;

        return sum;
    }

    int find_max(vector<int>& energy, int start, int k, int n, vector<int>& dp){
        if (start >= n) return INT_MIN;

        int currentEnergy = solve(energy, start, start + k, k, dp);

        int nextMax = find_max(energy, start + 1, k, n, dp);

        return max(currentEnergy, nextMax);
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n, INT_MIN);
        return find_max(energy, 0, k, n, dp);
    }
};