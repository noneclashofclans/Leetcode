class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int n = numBottles;
        int m = numExchange;
        int ans = n;


        for (int i = n; i >= m; m++){
            ans++;
            i -= m -1;
        }
        return ans;
    }
};  