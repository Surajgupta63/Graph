// DFS Traversal
    void DFS(vector<vector<int>>& adj, int u, vector<bool> &visited, vector<int> &ans){
        if(visited[u]) return;
        
        visited[u] = true;
        ans.push_back(u);
        
        for(auto &v : adj[u]){
            if(!visited[v]){
                DFS(adj, v, visited, ans);
            }
        }
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        vector<int> ans;
        vector<bool> visited(adj.size(), false);
        DFS(adj, 0, visited, ans);
        return ans;
    }
