class Solution {
public:
    using ll = long long;
    vector<long long> distance(vector<int>& nums) {
        
        int n = nums.size();
        
        
        vector<long long> ans(n);
    

        // if there is no other index with the same value, then we need to 
        // set that element to 0
        // else we need to find the sum of the absolute value of their indices

        // for(int i = 0; i < n; i++){
        //     bool found = false;
        //     long long temp = 0;
        //     for (int j = i+1; j < n; j++){
        //         if (nums[i] == nums[j]){
        //             found = true;
        //             temp += abs(i - j);
        //         }
        //     }

        //     for (int k = 0; k < i; k++){
        //         if (nums[i] == nums[k]){
        //             found = true;
        //             temp += abs(i - k);
        //         }
        //     }
            
        //     ans[i] = (long long) temp;
        // }

        // return ans;


        unordered_map<int, vector<int>> mapp;

        for (int i = 0; i < n; i++){
            mapp[nums[i]].push_back(i);
        }

        for (const auto&[number, indices] : mapp){
            int m = indices.size();


            vector<long long> prefSum(m+1, 0);
            for(int i = 0; i < m; i++){
                prefSum[i+1] = prefSum[i] + indices[i];
            }

            for (int i = 0; i < m; i++){
                ll lftSum = prefSum[i];
                ll rgtSum = prefSum[m] - prefSum[i+1];
                ll leftC = i;
                ll rgtC = m-i-1;

                ans[indices[i]] = (rgtSum-rgtC*1LL*indices[i]) + (leftC*1LL*indices[i]-lftSum);
            }
        }
        return ans;
    }
};