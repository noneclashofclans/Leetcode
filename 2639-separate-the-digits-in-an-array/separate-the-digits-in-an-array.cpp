class Solution {
public:
    string interTostring(int num){
        string ans = "";

        while(num){
            int ld = num % 10;
            ans += (ld + '0');
            num /= 10;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();


        for (int i = 0; i < n; i++){
            int num = nums[i];
            string s = interTostring(num);

            for (int j = 0; j < s.size(); j++){
                ans.push_back(s[j] - '0');
            }
        }

        return ans;
    }
};