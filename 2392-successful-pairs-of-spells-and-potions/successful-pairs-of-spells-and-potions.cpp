class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();

        vector<int> ans(n);
        vector<int> temp(m);

        sort(potions.begin(), potions.end());
        /*
        spell & potion is called success if
            "product of strength is >= success"
        */
        
        for (int i = 0; i < n; i++){
            int spell = spells[i];
            long long minPotion =  (success+spell-1)/spell;  //ceil(success/spell);

            int idx = lower_bound(potions.begin(), potions.end(), minPotion) - potions.begin();

            ans[i] = m - idx;
        }
        return ans;
    }           
};