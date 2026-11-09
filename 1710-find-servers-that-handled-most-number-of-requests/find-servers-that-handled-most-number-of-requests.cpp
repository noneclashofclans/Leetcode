class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        int m = load.size();
        vector<int> busiest;
        set<int> servers;
        // putting the servers
        for(int i = 0; i < k; i++)
            servers.insert(i);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> requestCount(k,0);
        int maxRequest = 0;
        for(int i = 0; i < n; i++){
            while(!pq.empty() && arrival[i] >= pq.top().first){
                servers.insert(pq.top().second);
                pq.pop();
            }
            if(servers.size() == 0) continue;
            int reqServer = i%k;
            auto iterativeServer = servers.lower_bound(reqServer);
            auto availableServer = -1;
            if (iterativeServer == servers.end()){
                availableServer = *servers.begin();
            }
            else{
                availableServer = *iterativeServer;
            }
            servers.erase(availableServer);
            pq.push({arrival[i] + load[i], availableServer});
            requestCount[availableServer]++;
            maxRequest = max(maxRequest, requestCount[availableServer]);
        }
        for(int i = 0; i < k; i++){
            if (requestCount[i] == maxRequest){
                busiest.push_back(i);
            }
        }
        return busiest;
    }
};