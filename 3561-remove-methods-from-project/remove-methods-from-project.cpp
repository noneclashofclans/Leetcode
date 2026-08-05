class Solution {
public:
    void dfs(int k, vector<vector<int>>& adj, vector<int>& visited){

        stack<int> st;
        st.push(k);
        visited[k] = 1;

        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for (auto nextNode : adj[node]){

                if (!visited[nextNode]){
                    visited[nextNode] = 1;
                    st.push(nextNode);
                }
                
            }
        }
        
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto &edge : invocations) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<int> visited(n, 0);

        dfs(k, adj, visited);

        vector<int> ans;

        for (auto &edge : invocations){
            int u = edge[0];
            int v = edge[1];
            
            if (!visited[u] && visited[v]) {
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i])
                ans.push_back(i);
        }

        return ans;
    }
};