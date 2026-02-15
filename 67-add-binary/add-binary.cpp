class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size(), m = b.size();

        string ans = "";
        int i = n-1, j= m - 1;

        int carry = 0;

        while (i >= 0 || j >= 0){
            int sum = carry;

            if (i >= 0){
                sum += a[i] - '0';
                i--;
            }

            if (j >= 0){
                sum+= b[j] - '0';
                j--;
            }

            ans.push_back((sum%2) + '0');
            carry = sum/2;    
        }   

        if (carry){
            ans.push_back('1');
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};