class Robot {
public:
    vector<int> dir;
    int idx = 0;
    bool moved = false;
    vector<pair<int, int>> pos;
    unordered_map<int, string> to_dir = {{0, "East"}, {1, "North"}, {2, "West"}, {3, "South"}};

    Robot(int width, int height) {
         for (int i = 0; i < width; i++){
            pos.emplace_back(i, 0);
            dir.emplace_back(0);
        }

        for (int i = 1; i < height; i++){
            pos.emplace_back(width - 1, i);
            dir.emplace_back(1);
        }

        for (int i = width - 2; i >= 0; i--){
            pos.emplace_back(i, height - 1);
            dir.emplace_back(2);
        }

        for (int i = height - 2; i > 0; i--){
            pos.emplace_back(0, i);
            dir.emplace_back(3);
        }
    }
    
    void step(int num) {
        moved = true;
        idx = (idx + num) % pos.size();
    }
    
    vector<int> getPos() {
        // returns {x, y}
        return {pos[idx].first, pos[idx].second};
    }
    
    string getDir() {
        // to find the current direction   
        if (!moved) return "East";
        if (idx == 0) return "South";
        return to_dir[dir[idx]];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */