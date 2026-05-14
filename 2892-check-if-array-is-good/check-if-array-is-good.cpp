class Solution {
public:
    bool isGood(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());

        if(nums.size() != mx + 1)
            return false;

        vector<int> count(mx + 1, 0);

        for(int x : nums) {
            if(x < 1 || x > mx)
                return false;
            count[x]++;
        }

        for(int i = 1; i < mx; i++) {
            if(count[i] != 1)
                return false;
        }

        return count[mx] == 2;
    }
};