class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        auto simulate = [&](vector<int> arr, int start, int dir) {
            int i = start;
            while (i >= 0 && i < n) {
                if (arr[i] == 0)
                    i += dir;
                else {
                    arr[i]--;
                    dir = -dir;
                    i += dir;
                }
            }
            for (int x : arr)
                if (x != 0) return false;
            return true;
        };

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (simulate(nums, i, 1)) cnt++;
                if (simulate(nums, i, -1)) cnt++;
            }
        }

        return cnt;
    }
};
