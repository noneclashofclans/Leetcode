class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int,int> lastRain;
        set<int> dry;


        /*
            if rains[i] > 0, there will be rain on the lake
            if rains[i] = 0, means no rain, and we can dry any other lake

            // return 

            1) ans.length
            2) if rains[i] > 0, then ans[i] = -1
            3) ans[i] = the lake you want to dry in the ith day, iff rains[i] = 0
        */
    
        // int cnt_pos = 0;
        // int zero_cnt = 0;
        // int zero_idx = -1;
        // int prev_idx = -1;

        // for (int i = 0; i < n; i++){
        //     if (rains[i] > 0) ans.push_back(-1);
        //     cnt_pos++;
        //     if (rains[i] == 0){
        //         zero_idx = i;
        //         prev_idx = (i-1);
        //         break;
        //     }
        // }

        // int j = zero_idx;
        // while (j < n && j == 0){
        //     zero_cnt++;
        // }

        // if (cnt_pos == zero_cnt){
        //     for (int i = prev_idx; i >= 0; i--){
        //         ans.push_back(rains[i]);
        //     }
        // }
        // else if (cnt_pos > zero_cnt){
        //     // it floods
        //     ans.resize(0);
        // }

        // return ans;

        for (int i = 0; i < n; i++){
            if (rains[i] == 0){
                dry.insert(i);
            }

            else {
                ans[i] = -1;
                if (lastRain.count(rains[i])){
                    int prev = lastRain[rains[i]];
                    auto it = dry.upper_bound(prev);
                    if (it == dry.end()) return {};
                    ans[*it] = rains[i];
                    dry.erase(it);
                }
            }
            lastRain[rains[i]] = i; 
        }

        return ans;
    }
};
