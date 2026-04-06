class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n = commands.size();
        int m = obstacles.size();

        set<pair<int,int>> obs;
        for (auto &o : obstacles) {
            obs.insert({o[0], o[1]});
        }

        // -1: right 90 degree
        // -2: left 90 degree

        int x_dist = 0, y_dist = 0;
        string current_dir = "north"; 
        int max_dist = 0;


        for (int i = 0; i < n; i++){
            if (commands[i] == -1) {
  
                if (current_dir == "north") current_dir = "east";
                else if (current_dir == "east") current_dir = "south";
                else if (current_dir == "south") current_dir = "west";
                else current_dir = "north";
            }
            else if (commands[i] == -2) {
     
                if (current_dir == "north") current_dir = "west";
                else if (current_dir == "west") current_dir = "south";
                else if (current_dir == "south") current_dir = "east";
                else current_dir = "north";
            }

            else {
                for (int step = 0; step < commands[i]; step++) {
                    int nx = x_dist, ny = y_dist;

                    if (current_dir == "north") ny++;
                    else if (current_dir == "south") ny--;
                    else if (current_dir == "east") nx++;
                    else nx--;

                    if (obs.count({nx, ny})) break;

                    x_dist = nx;
                    y_dist = ny;

                    max_dist = max(max_dist, x_dist*x_dist + y_dist*y_dist);
                }
            }
        }

        return max_dist;
    }
};