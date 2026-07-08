class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // brute force
        unordered_map<string, int> freq;
        for (const string& word : words) {
            freq[word]++;
        }
        

        vector<pair<string, int>> vec(freq.begin(), freq.end());

        sort(vec.begin(), vec.end(), [](const pair<string, int>& a, const pair<string, int>& b){
            if (a.second != b.second){
                return a.second > b.second;
            }
            return a.first < b.first;
        });


        vector<string> ans; 

        for(int i = 0; i < k; i++){
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};