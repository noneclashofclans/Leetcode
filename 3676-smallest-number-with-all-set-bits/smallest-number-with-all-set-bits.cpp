class Solution {
public:
    // const int upper = 1e4;
    // string check(int x){
    //     string res = "";
    //     while (x != 0){
    //         int rem = x % 2;
    //         res += rem;
    //         x = x / 2;
    //     }
    //     reverse(res.begin(), res.end());
    //     return res;
    // }

    int smallestNumber(int n) {
        // int x = n;
        // // find the binary form and store in a string 

        // while (x <= upper){
        //     string s = check(x);
        //     for (char x : s){
        //         if (x == '0') break;
        //     }
        //     x++;
        // }
        // return 
        int ans = 0;
        for (int i = 0; i <= 1000; i++){
            int res = pow(2, i);
            if (res > n){
                ans = res - 1;
                break;
            }
            else continue;
        }
        return ans;
    }
};