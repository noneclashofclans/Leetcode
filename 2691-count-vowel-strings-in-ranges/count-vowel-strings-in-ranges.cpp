class Solution {
public:
    bool isVowel(char& c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();

        vector<int> prefix_sum(n+1, 0); //make a prefix sum array
        // (n+1) size, to avoid segmentation fault
        for(int i = 0; i < (n+1); i++){
            prefix_sum[i] = 0;
        }
        //Now compute the prefix sum
        for (int i = 0; i < n; i++){
            //finding the start and ending charecter of each word
            char start = words[i][0];
            char end = words[i].back();

            if (isVowel(start) && isVowel(end)){
                prefix_sum[i+1] = prefix_sum [i] + 1;
            }
            else{
                prefix_sum[i+1] = prefix_sum[i];
            }
        }
        //Now computing for each query
        vector<int> ans;
        for(auto q : queries){
            //count = query(r+1)-query(l)
            int count = prefix_sum[q[1]+1]-prefix_sum[q[0]];
            ans.push_back(count);
        }
        return ans;
    }
};