class Solution {
public:
    string solve(int n){
        // starts from low and ends at n
        if (n == 1) return "1";
        string prev = solve(n-1);

        string ans = "";

        int i = 0;

        while(i < prev.size()){
            int c = 1;
            while(i+1 < prev.size() && prev[i] == prev[i+1]){
                i++;
                c++;
            }

            ans += to_string(c) + prev[i];
            i++;
        }
        return ans;
    }
    string countAndSay(int n) {
       return solve(n);      
    }
};