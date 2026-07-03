class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int o = 0, t = 0;

        for(int x : nums){
            o = (o ^ x) & ~t;
            t = (t ^ x) & ~o; 
        }
        return o;
    }
};