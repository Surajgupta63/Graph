// Kosaraju's Algorithm
// T.C : O(V+E)
// S.C : O(V+E)
class Solution {
  public:
    void topoSortDFS(vector<vector<int>> &adj, int u, vector<bool> &visited, stack<int> &st){
        visited[u] = true;
        
        for(int &v : adj[u]){
            if(!visited[v]){
                topoSortDFS(adj, v, visited, st);
            }
        }
        st.push(u);
    }
    
    void DFS(vector<vector<int>> &reversedAdj, int u, vector<bool> &visited){
        visited[u] = true;
        
        for(int &v : reversedAdj[u]){
            if(!visited[v]){
                DFS(reversedAdj, v, visited);
            }
        }
    }
    
    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size();
        stack<int> st;
        vector<bool> visited(V, false);
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                topoSortDFS(adj, i, visited, st);
            }
        }
        
        vector<vector<int>> reversedAdj(V);
        for(int u=0; u<V; u++){
            for(int &v : adj[u]){
                reversedAdj[v].push_back(u);
            }
        }
        
        int count = 0;
        visited = vector<bool>(V, false);
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!visited[node]){
                DFS(reversedAdj, node, visited);
                count++;
            }
            
        }
        return count;
    }
};
