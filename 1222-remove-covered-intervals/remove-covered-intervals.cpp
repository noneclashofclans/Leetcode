class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int n = intervals.size();
       
        vector<bool> covered(n, false);

        for(int i = 0; i<n; i++){
            int a = intervals[i][0];
            int b = intervals[i][1];

            for(int j = 0; j < n; j++){
                if (i == j) continue;
                int c = intervals[j][0];
                int d = intervals[j][1];

                if (c <= a && b <= d){
                    covered[i] = true;
                    break;
                }
            }
        }

        int ans = 0;
        
        for(auto x : covered){
            if (!x) ans++;
        }
        return ans;
    }
};