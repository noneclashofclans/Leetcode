class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
    vector<long long> ans(n);
    unordered_map<int, vector<int>> map;

    // Populate the map with indices for each number
    for (int i = 0; i < n; i++) {
        map[nums[i]].push_back(i);
    }

    // Compute results
    for (const auto& [number, indices] : map) {
        int m = indices.size();
        vector<long long> prefixSum(m + 1, 0);

        // Compute prefix sums
        for (int i = 0; i < m; i++) {
            prefixSum[i + 1] = prefixSum[i] + indices[i];
        }

        // Calculate the result for each index
        for (int i = 0; i < m; ++i) {
            long long leftSum = prefixSum[i];
            long long rightSum = prefixSum[m] - prefixSum[i + 1];
            long long leftCount = i;
            long long rightCount = m - i - 1;

            ans[indices[i]] = (rightSum - rightCount * 1LL * indices[i]) 
                            + (leftCount * 1LL * indices[i] - leftSum);
        }
    }

    return ans;
    }
};