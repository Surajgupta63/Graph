// Using Priority Queue
// T.C : O(V*Vlog(V))
// S.C : O(V)
class Solution{
    public:
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int V = adj.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans(V, INT_MAX);
        
        ans[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){ // O(V)
            pair<int, int> p = pq.top();
            pq.pop(); // log(V)
            
            int d = p.first;
            int u = p.second;
            
            for(auto &vec : adj[u]){ // O(E)
                int v  = vec.first;
                int wt = vec.second;
                
                if(d + wt < ans[v]){
                    ans[v] = d + wt;
                    pq.push({d+wt, v}); // log(V)
                }
            }
            
        }
        return ans;
    }
};


// Using Set
// T.C : O(V*Vlog(V))
// S.C : O(V)
class Solution{
    public:
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int V = adj.size();
        set<pair<int, int>> st;
        vector<int> ans(V, INT_MAX);
        
        ans[src] = 0;
        st.insert({0, src});
        
        while(!st.empty()){
            auto &it = *st.begin();
            int d = it.first;
            int u = it.second;
            st.erase(it);
            
            for(auto &vec : adj[u]){
                int node = vec.first;
                int wt   = vec.second;
                
                if(d + wt < ans[node]){
                    
                    if(ans[node] != INT_MAX){
                        st.erase({ans[node], node});
                    }
                    
                    ans[node] = d+wt;
                    st.insert({d+wt, node});
                }
            }
        }
        return ans;
    }
};

