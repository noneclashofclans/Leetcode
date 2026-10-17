class Solution {
public: 
    int digitSum(int a){
        int s = 0;
        while (a){
            int digit = a % 10;
            s += digit;
            a /= 10;
        }
        return s;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> p;

        for (int i = 0; i < n; i++){
            p.push_back({nums[i], i});
        }

        sort(p.begin(), p.end(), [&](auto a, auto b){
            int s_a = digitSum(a.first);
            int s_b = digitSum(b.first);

            if (s_a == s_b) return a.first < b.first;

            else return s_a < s_b;
        });

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++){
            if (visited[i] || p[i].second == i){
                continue;
            }

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = p[j].second;
                cycleSize++;
            }

            if (cycleSize > 1) {
                swaps += cycleSize - 1;
            }
        }
        return swaps;
    }
};