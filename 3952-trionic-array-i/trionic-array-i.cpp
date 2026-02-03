class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;

        int p = 0;

        while (p + 1 < n && nums[p] < nums[p + 1]) {
            p++;
        }
        if (p == 0 || p == n - 1) return false;

        int q = p;

        while (q + 1 < n && nums[q] > nums[q + 1]) {
            q++;
        }
        if (q == p || q == n - 1) return false;

        int r = q;
        while (r + 1 < n && nums[r] < nums[r + 1]) {
            r++;
        }

        return r == n - 1;
    }
};