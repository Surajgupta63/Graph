// Topological Sort Using DFS
// T.C : O(V+E)
// S.C : O(V+V)
class Solution{
    public:
    void topSortDFS(vector<vector<int>>& adj, int u, vector<bool> &visited, stack<int> &st){
        visited[u] = true;
        for(int &v : adj[u]){
            if(!visited[v]){
                topSortDFS(adj, v, visited, st);
            }
        }
        st.push(u);
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<bool> visited(V, false);
        stack<int> st;
        
        for(int i=0; i<V; i++){
            if(!visited[i]) 
                topSortDFS(adj, i, visited, st);
        }
        
        vector<int> topoSort;
        while(!st.empty()){
            topoSort.push_back(st.top());
            st.pop();
        }
        
        return topoSort;
    }
};

// Topological Sort Using BFS(Kahn's Algorithm)
// T.C : O(V+E)
// S.C : O(V+V)
class Solution{
    public:
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> indegree(V, 0);
        for(int u=0; u<V; u++){
            for(int &v : adj[u]){
                indegree[v]++;
            }
        }
        
        queue<int> q;
        for(int v = 0; v<V; v++){
            if(indegree[v] == 0){
                q.push(v);
            }
        }
        
        vector<int> topoSort;
        
        while(!q.empty()){
            int u = q.front();
            topoSort.push_back(u);
            q.pop();

            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        return topoSort;
    }
};
