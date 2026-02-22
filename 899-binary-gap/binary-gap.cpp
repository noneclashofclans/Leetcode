class Solution {
public:
    string binary(int n){
        string ans = "";
        while (n){
            int rem = n % 2;
            ans += (rem + '0');
            n /= 2;
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
    int binaryGap(int n) {
        string str = binary(n);

        int size = str.size();
        
        int idx_1 = -1;       
        
        int max_distance = 0; 

        for (int i = 0; i < size; i++){
            if (str[i] == '1'){
                if (idx_1 != -1){
                    int curr_dist = i - idx_1;
                    max_distance = max(max_distance, curr_dist);
                }
                idx_1 = i; 
            }
        }

        return max_distance;
    }
};