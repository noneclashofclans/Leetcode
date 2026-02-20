class Solution {
public:
    string makeLargestSpecial(string s) {
        int count = 0; 
        vector<string> ans;
        int start = 0; 

        for (int i = 0; i < s.size(); i++){
            if(s[i] == '1') count++;
            else count--;

            if (count == 0){
                string make = makeLargestSpecial(s.substr(start+1, i-start-1));
                ans.push_back("1" + make + "0"); // "11011000" -> 
                                                 // string first = "10"
                                                 // string second = "1100"
                                                 // then swap for form new string 'make'
                                                 // but '1' is left at start and '0' at end 
                start = i+1;
            } 
        }
        sort(ans.begin(), ans.end(), greater<string>());
        string res = "";
            
        for (auto &x : ans) res += x;

        return res;
    }
};