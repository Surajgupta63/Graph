// Using DFS
// T.C : O(V+E)
// S.C : O(V+V)
class Solution{
    public:
    bool isCycleDFS(vector<vector<int>> &adj, int u, vector<bool> &visited, vector<bool> &currRec){
        visited[u] = true;
        currRec[u] = true;
        
        for(int &v : adj[u]){
            if(visited[v] && currRec[v]) return true;
            
            if(isCycleDFS(adj, v, visited, currRec)) return true;
        }
        
        currRec[u] = false;
        
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<bool> visited(V, false);
        vector<bool> currRec(V, false);
        
        for(int i=0; i<V; i++){
            if(!visited[i] && isCycleDFS(adj, i, visited, currRec)) return true;
        }
        return false;
    }
};

// Using BFS (Topological Sort (Kahn's Algorithm))
// T.C : O(V+E)
// S.C : O(V+V)
class Solution{
    public:
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<int> indegree(V, 0);
        for(int u=0; u<V; u++){
            for(int &v : adj[u]){
                indegree[v]++;
            }
        }
        
        queue<int> q;
        for(int v=0; v<V; v++){
            if(indegree[v] == 0){
                q.push(v);
            }
        }
        
        int count = 0;
        
        while(!q.empty()){
            int u = q.front();
            count++;
            q.pop();
            
            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        
        if(count == V) return false;
        return true;
    }
};
