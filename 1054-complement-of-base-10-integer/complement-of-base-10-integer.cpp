class Solution {
public:
    string complement_string(string& s){
        string res = "";
        for (auto x : s){
            if (x == '1') res += '0';
            else res += '1'; 
        }

        return res;
    }

    int base_10_flipped_string(string &s){
        string ans = complement_string(s);

        int n = s.size();   
        int sum = 0;

        for (int i = n-1; i >= 0; i--){
            if (ans[i] == '1'){
                sum += pow(2, n-1-i);
            }
            else continue;
        }

        return sum;
    }

    string tobinary(int n){
        string ans = "";

        while (n){
            int rem = n % 2;
            ans += rem + '0';
            n /= 2;
        }

        reverse (ans.begin(), ans.end());

        return ans;
    }
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        string ans = tobinary(n);

        // 5: "0101"
        int anss = base_10_flipped_string(ans);

        return anss;
    }
};