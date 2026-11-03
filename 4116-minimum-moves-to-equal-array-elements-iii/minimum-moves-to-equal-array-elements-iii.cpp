class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int omax = *max_element(nums.begin(), nums.end());
        int min_moves = 0;

        for (int i = 0; i < n; i++){
            int needed = omax - nums[i];
            if (needed == 0) continue;
            min_moves += needed;
        }   
        return min_moves;
    }
};