class Solution {
public:
    
    int find_waviness(int n){
        string s = to_string(n);

        int peakCount = 0;
        int valleyCount = 0;

        for (int i = 1; i < (int)s.size() - 1; i++) {
            if (s[i] > s[i - 1] && s[i] > s[i + 1]) {
                peakCount++;
            }
            else if (s[i] < s[i - 1] && s[i] < s[i + 1]) {
                valleyCount++;
            }
        }

        return peakCount + valleyCount;
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;

        for (int i = num1; i <= num2; i++){
            ans += find_waviness(i);
        }

        return ans;
    }
};