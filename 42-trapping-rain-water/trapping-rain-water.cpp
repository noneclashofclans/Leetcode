class Solution {
public:
    bool is_increasing_height(vector<int> &arr){
        for (int i = 1; i < arr.size(); i++){
            if (arr[i] - arr[i-1] != 1) return false;
        }
        return true;
    }
    int trap(vector<int>& arr) {
        int totalWater = 0;
        if (is_increasing_height(arr)) return totalWater;
        if (arr.size() < 3) return totalWater;

        int left_max = INT_MIN, right_max = INT_MIN;

        int start = 0;
        int end = arr.size()-1;
        
        //i) find the max element at the left side and right side
        while (start < end){
            if (arr[start] < arr[end]){
                //find the max element at left side
                if (arr[start] > left_max){
                    left_max = arr[start];
                }
                else {
                    totalWater += left_max - arr[start];
                }
                start ++;
            }
            
            else{
                //find max element at right side
                if (arr[end] > right_max){
                    right_max = arr[end];
                }
                else{
                    totalWater += right_max - arr[end];
                }
                end--;
            }
        }
        return totalWater;
    }
};