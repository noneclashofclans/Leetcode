class Solution {
public:
    const int mod = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        for (auto &q : queries){
            int start = q[0];
            int end = q[1];
            int k = q[2];
            int v = q[3];

            while (start <= end){
                nums[start] = (nums[start] * 1LL * v) % mod;
                start += k;
            }
        }

        int ans = 0;

        for (int &x : nums){
            ans ^= x;
        }         

        return ans;
    }
};