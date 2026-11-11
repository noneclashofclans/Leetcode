class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // total contribution to cost1 = need1
        // total contribution to cost2 = need2
        // if (need1 == 0 && need2 == 0) return 0;
        // else if (need1 == cost1 && need2 == cost2) return max(cost1,cost2) * costBoth;
        // else return need1 * cost1 + need2 * cost2;
        long long min, max, ans;
        min = fmin(need1, need2);
        max = fmax(need1, need2);
        ans = (long long) need1 * cost1 + (long long) need2 * cost2;
        ans = fmin(ans, (long long) min * costBoth + (long long) (need1 - min)*cost1 + (long long)(need2 -min)*cost2);
        ans = fmin(ans,(long long)max*costBoth);
        return ans;
    }
};