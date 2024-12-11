class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<pair<int,int>> event;

        for (int i : nums){
            event.emplace_back(i-k,1);
            event.emplace_back(i+k+1,-1);
        }

        sort(event.begin(),event.end());

        int max_beauty = 0, current_overlap = 0;
        for (const auto& [pos, type] : event) {
            current_overlap += type; 
            max_beauty = max(max_beauty, current_overlap); 
        }
        return max_beauty;    
    }
};