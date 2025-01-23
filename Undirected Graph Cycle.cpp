// Using DFS
// T.C : O(V+E) + O(2V)
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


// Using DSU 
// T.C : O(V+E)
// S.C : O(V)
class Solution{
    public:
    
    int find(int x, vector<int> &parent){
        if(x == parent[x]) return x;
        
        return parent[x] = find(parent[x], parent);
    }
    
    void Union(int x, int y, vector<int> &parent, vector<int> &rank){
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);
        
        if(x_parent == y_parent) return;
        
        if(rank[x_parent] > rank[y_parent])
            parent[y_parent] = x_parent;
        else if(rank[x_parent] < rank[y_parent])
            parent[x_parent] = y_parent;
        else{
            parent[x_parent] = y_parent;
            rank[y_parent] += 1;
        }
    }
    
	int detectCycle(int V, vector<int>adj[])
	{
	    vector<int> parent(V, -1);
	    vector<int> rank(V, 1);
	    
	    for(int i=0; i<V; i++){
	        parent[i] = i;
	    }
	    
	    for(int u=0; u<V; u++){
	        for(int &v : adj[u]){
	            if(u < v){
	                int u_parent = find(u, parent);
	                int v_parent = find(v, parent);
	                if(u_parent == v_parent) return true;
	                Union(u_parent, v_parent, parent, rank);
	            }
	        }
	    }
	    return false;
	}
};

