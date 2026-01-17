class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
        int n = arr.size();
        
        int cnt = 0;
        int curr = 0;

        for (int i = 2; i < n; i++){
            if (arr[i] - arr[i - 1] == arr[i - 1] - arr[i - 2]){
                curr ++;
                cnt += curr;
            }
            else {
                curr = 0;
            }
        }
        return cnt;
    }   
};