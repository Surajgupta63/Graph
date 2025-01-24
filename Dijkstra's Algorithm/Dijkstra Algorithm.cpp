// Using Priority Queue
// T.C : O(V + E)
// S.C : O(V)
class Solution{
    public:
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int V = adj.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans(V, INT_MAX);
        
        ans[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();
            
            int d = p.first;
            int u = p.second;
            
            for(auto &vec : adj[u]){
                int v  = vec.first;
                int wt = vec.second;
                
                if(d + wt < ans[v]){
                    ans[v] = d + wt;
                    pq.push({d+wt, v});
                }
            }
            
        }
        return ans;
    }
};
