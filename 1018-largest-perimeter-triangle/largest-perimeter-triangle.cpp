class Solution {
public:
//    int binarySearch(int i, int j, int k, vector<int>& nums){
//         int n = nums.size();    
//         bool can_form = false;
//         int ans = 0;

//         while (j < k){
//             int mid = j + (k - j)/2;
//             int currentPerimeter = (nums[i] + nums[j] + nums[k]);
            
//             if (nums[i] + nums[mid] > nums[k]){
//                 ans = max(ans, currentPerimeter);
//                 j = mid + 1;
//             }
//             else k = mid - 1;
//         }
//         return ans;
//     }
    int largestPerimeter(vector<int>& nums) {
        // int n = nums.size();
        // int res = 0;
        // sort(nums.begin(), nums.end());
        
        // for(int i = 0; i < n-2; i++){
        //     // for (int j = i+1; j < n-1; j++){
        //     //     for(int k = j+1; k < n; k++){
        //     //         int currentPerimeter = (nums[i] + nums[j] + nums[k]);
        //     //         if ((nums[i] + nums[j] > nums[k]) && (nums[j] + nums[k] > nums[i]) && (nums[i] + nums[k] > nums[j])){
        //     //             can_form = true;
        //     //             ans = max(ans, currentPerimeter);
        //     //         }else break;
        //     //     }
        //     // }
        //     // while (j < k){
        //     //     int currentPerimeter = (nums[i] + nums[j] + nums[k]);
        //     //     if ((nums[i] + nums[j] > nums[k]) && (nums[j] + nums[k] > nums[i]) && (nums[i] + nums[k] > nums[j])){
        //     //         can_form = true;
        //     //         ans = max(ans, currentPerimeter);
        //     //     }else break;
        //     //     j++; k--;
        //     // }
        //     res = max(res, binarySearch(i, i+1, n-1, nums));
        // }
        // return res;

        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int k = n - 1; k >= 2; --k) {
            if (nums[k-2] + nums[k-1] > nums[k])
                return nums[k-2] + nums[k-1] + nums[k];
        }
        return 0;
    }
};