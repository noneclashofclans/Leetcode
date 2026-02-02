class Solution {
public:
    typedef long long ll;
    typedef pair<ll, ll> p;

    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();

        set<p> kMin, rem;
        ll sum = 0;

        int i = 1;
        while (i <= dist) {
            kMin.insert({nums[i], i});
            sum += nums[i];

            if (kMin.size() > k - 1) {
                p temp = *kMin.rbegin();
                sum -= temp.first;
                rem.insert(temp);
                kMin.erase(temp);
            }
            i++;
        }

        ll ans = LLONG_MAX;

        while (i < n) {
            kMin.insert({nums[i], i});
            sum += nums[i];

            if (kMin.size() > k - 1) {
                p temp = *kMin.rbegin();
                sum -= temp.first;
                rem.insert(temp);
                kMin.erase(temp);
            }

            ans = min(ans, sum);

            p remove = {nums[i - dist], i - dist};

            if (kMin.count(remove)) {
                kMin.erase(remove);
                sum -= remove.first;

                if (!rem.empty()) {
                    p temp = *rem.begin();
                    kMin.insert(temp);
                    sum += temp.first;
                    rem.erase(temp);
                }
            } else {
                rem.erase(remove);
            }

            i++;
        }

        return ans + nums[0];
    }
};
