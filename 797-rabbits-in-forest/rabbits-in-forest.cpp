class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        unordered_map<int,int> rabbits;

        for (int rabbit:answers){
            rabbits[rabbit]++;
        }
        int res = 0;
        for (const auto &pair:rabbits){
            int rab = pair.first;
            int count_of_rab = pair.second;

            int group_size = rab + 1; //should be in pairs
            int groups = (count_of_rab + rab)/group_size;

            res += groups * group_size;
        }
        return res;
    }
};