class Solution {
public:
    void rotate(vector<int>& a, int b){
        int n = a.size();
        b = b%n;
        reverse(a.begin(), a.end());
        reverse(a.begin(), a.begin()+b);
        reverse(a.begin()+b, a.end());
    }
    int convert_to_num(vector<int>& a){
        string res = "";
        for (int x : a) res += char('0' + x);
        return stoi(res);
    }
    vector<int> to_arr(const string& s) {
        vector<int> ans;
        for (char c : s) ans.push_back(c - '0');
        return ans;
    }

    string vecToStr(const vector<int>& a) {   
        string s = "";
        for (int x : a) s += char('0' + x);
        return s;
    }
    void add(vector<int>& arr, int val){
        int n = arr.size();
        for (int i = 1; i < n; i += 2) {
            arr[i] = (arr[i] + val) % 10;
        }
    }
    string findLexSmallestString(string s, int a, int b) {
        // rotate -> add -> rotate -> add -> ...
         vector<int> start = to_arr(s);

        
        queue<vector<int>> q;
        unordered_set<string> vis;

        string best = s;
        q.push(start);
        vis.insert(vecToStr(start));

        while (!q.empty()) {
            vector<int> cur = q.front(); q.pop();
            string curS = vecToStr(cur);
            if (curS < best) best = curS;

            vector<int> added = cur;
            add(added, a);
            string addedS = vecToStr(added);
            if (!vis.count(addedS)) {
                vis.insert(addedS);
                q.push(added);
            }

           
            vector<int> rotated = cur;
            rotate(rotated, b);
            string rotS = vecToStr(rotated);
            if (!vis.count(rotS)) {
                vis.insert(rotS);
                q.push(rotated);
            }
        }

        return best;
    }
};