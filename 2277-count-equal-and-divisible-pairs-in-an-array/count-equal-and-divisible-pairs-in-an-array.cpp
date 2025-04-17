class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        // O(n^2)
        // for (int i = 0; i < n-1; i++){
        //     for (int j = i+1; j < n; j++){
        //         if(nums[i] == nums[j] && (i*j) % k == 0){
        //             cnt++;
        //         }
        //     }
        // }

        unordered_map<int,vector<int>> map; // num vs. index
        for (int i = 0; i < n; i++){
            for (auto j : map[nums[i]]){
                if ((i*j)%k == 0) cnt++;
            }
            map[nums[i]].push_back(i);
        }
        return cnt;
    }
};