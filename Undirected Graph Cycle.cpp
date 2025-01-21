// Using DFS
// T.C : O(V+E)
// S.C : O(V)
class Solution{
    public:
    bool isCycleDFS(vector<vector<int>>& adj, int u, vector<bool> &visited, int p){
        visited[u] = true;
        
        for(int &v : adj[u]){
            if(v == p) continue;
            if(visited[v]) return true;
            
            if(isCycleDFS(adj, v, visited, u)) return true;
        }
        
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        
        int V = adj.size();
        vector<bool> visited(V, false);
        
        for(int i=0; i<V; i++){
            if(!visited[i] && isCycleDFS(adj, i, visited, -1)){
                return true;
            }
        }
        return false;
        
    }
};

// Using BFS
// T.C : O(V+E)
// S.C : O(V)
class Solution{
    public:
    bool isCycleBFS(vector<vector<int>>& adj, int u, vector<bool> &visited){
        queue<pair<int, int>> q;
        q.push({u, -1});
        visited[u] = true;
        
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            
            int node   = p.first;
            int parent = p.second;
            
            for(int &v : adj[node]){
                if(!visited[v]){
                    q.push({v, node});
                    visited[v] = true;
                }
                else if(v != parent) return true;
            }
        }
        return false;    
    }
    bool isCycle(vector<vector<int>>& adj) {
        
        int V = adj.size();
        vector<bool> visited(V, false);
        
        for(int i=0; i<V; i++){
            if(!visited[i] && isCycleBFS(adj, i, visited)){
                return true;
            }
        }
        return false;   
    }
};

