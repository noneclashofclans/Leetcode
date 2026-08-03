class Solution {
public: 
    vector<int> dp;

    int solve(int i, vector<int>& stoneValue){
        int n = stoneValue.size();
        if (i >= n) return 0;
        int ans = INT_MIN;

        if (dp[i] != INT_MIN) return dp[i];
        int s = 0;
        for (int k = 0; k < 3 && i + k < n; k++){
            s += stoneValue[i + k];
            ans = max(ans, s - solve(i + k + 1, stoneValue));
        }
        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        // alice starts first
        // every player can take either 1,2,3 or all stones from the start
        // since alice starts 1st and she can either take up 1st or 2nd or 3rd stone from the start,  
        // and with a max of 3 stones at every chance, we need to find the total score for alice
        // to make her win. If alice_score > bob_score then alice wins, else there is a tie or bob wins.
        dp.assign(stoneValue.size(), INT_MIN);

        int diff = solve(0, stoneValue);

        if (diff > 0)
            return "Alice";
        else if (diff < 0)
            return "Bob";
        else
            return "Tie";
    }
};