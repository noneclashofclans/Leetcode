class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int k, j, current;
        int ans = nums[0] + nums[1] + nums[2];
        //sort the array
        sort(nums.begin(),nums.end());
        for (int i = 0; i<n; i++){
            j = i+1, k = n-1;
            while (j<k){
                current = nums[i]+nums[j]+nums[k];
                if (abs(current-target)<abs(ans-target)){
                    ans = current;
                }
                current < target ? j++ : k--;
            } 
        }
        return ans;
    }
};