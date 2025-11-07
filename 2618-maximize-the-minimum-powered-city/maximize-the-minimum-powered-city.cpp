class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();

        vector<long long> pref(n + 1);
        for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + stations[i];

        vector<long long> base(n);
        for (int i = 0; i < n; i++) {
            int l = max(0, i-r), h = min(n-1, i+r);
            base[i] = pref[h+1] - pref[l];
        }

        auto ok = [&](long long need) {
            long long kk = k;
            long long add = 0;
            vector<long long> diff(n);
            for (int i = 0; i < n; i++) {
                if (i - r - 1 >= 0) add -= diff[i-r-1];
                long long cur = base[i] + add;
                if (cur < need) {
                    long long d = need - cur;
                    if (d > kk) return false;
                    kk -= d;
                    diff[min(n-1, i+r)] += d;
                    add += d;
                }
            }
            return true;
        };

        long long lo = 0, hi = 1e18, ans = 0;
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            if (ok(mid)) ans = mid, lo = mid + 1;
            else hi = mid - 1;
        }
        return ans;
    }
};