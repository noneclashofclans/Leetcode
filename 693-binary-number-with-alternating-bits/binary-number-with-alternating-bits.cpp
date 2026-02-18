class Solution {
public:
    string binary(int n){
        string res = "";
        while(n){
            int remainder = n%2;
            res += remainder;
            n /= 2;
        }
        reverse(res.begin(), res.end());

        return res;
    }
    bool hasAlternatingBits(int n) {
        string binary_form = binary(n);
        for (int i = 0; i < binary_form.size()-1; i++){
            if(binary_form[i] == binary_form[i+1]) return false;
        }
        return true;
    }
};