class Solution {
    public int maxSubArray(int[] nums) {
        int current_max = 0;
        int omax = Integer.MIN_VALUE;

        for (int i=0;i<nums.length;i++){
            if (current_max < 0){
                current_max = nums[i];
            }
            else{
                current_max = current_max + nums[i];
            }

            omax = Math.max(omax,current_max);
        }

        return omax;
    }
}