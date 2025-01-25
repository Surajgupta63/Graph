
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, vector<pair<int, int>>> adj;
        vector<int> result(n+1, INT_MAX);

        for(auto &vec : times){ // O(E)
            int u = vec[0];
            int v = vec[1];
            int t = vec[2];
            adj[u].push_back({v, t});
        }
        
        result[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){ // O(V)
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop(); //log(E)

            for(auto P : adj[node]){ // O(E)
                int newNode = P.first;
                int newTime = P.second;

                if(time + newTime < result[newNode]){
                    result[newNode] = time + newTime;
                    pq.push({time+newTime, newNode}); // log(E)
                }
            }
        }

        int ans = *max_element(result.begin()+1, result.end());
        return ans == INT_MAX ? -1 : ans;
    }
};
