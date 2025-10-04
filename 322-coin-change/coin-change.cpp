class Solution {
public:
    unordered_map<int,int> dp;
    int solve(vector<int>& coins, int amount){
        if (amount == 0) return 0;
        if (amount < 0) return -1;

        if (dp.count(amount)) return dp[amount];

        int cnt = INT_MAX;
        
        for (int c : coins){
            int ans = solve(coins, amount-c);

            if (ans >= 0 && ans < cnt){
                cnt = min(1+ans, cnt);  
            }
        }

        return dp[amount] = (cnt == INT_MAX ? -1 : cnt);
    }
    int coinChange(vector<int>& coins, int amount) {

        return solve(coins, amount); 
    }
};